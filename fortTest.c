#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
int main(){
	pid_t pid;
	int x;
	x=0;

	printf("original pid:%d\n",pid);
	printf("fork start\n");
	pid=fork();
	printf("fork end\n");

	if(pid > 0){//parents
		x=1;
		printf("parents PID: %d, x:%d, pid:%d\n", getpid(),x,pid);
	}else if(pid== 0){
		x=2;
		printf("child PID: %d, x:%d, pid:%d\n", getpid(), x, pid);
		exit (0);
	}else{
		printf("fork fail\n");
		return -1;
	}
	
	return 0;
}
