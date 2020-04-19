#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
//
int main(int argc, char *argv[]) {
    char buf[128];
    pid_t pid;

    char * cwd;
    cwd=getcwd(NULL,260);
    while(1) {
	    printf("%s:",cwd);
        memset(buf, 0, sizeof(buf));
        fgets(buf, sizeof(buf) - 1, stdin);
        
        buf[strlen(buf) - 1] = '\0'; 
        if(!strncmp(buf, "quit", strlen(buf))) {
            return -1;
        }

        pid = fork();
        if(pid < 0) {
            perror("fork error\n");
            return -1;
        }
        else if(pid == 0) {
            execlp(buf, buf, NULL);
	    printf("input is:%s\n",buf);
            exit(0);
        }
        else {
            wait(0);
        }
    }

    return 0;
}
