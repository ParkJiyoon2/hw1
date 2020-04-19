#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <sys/wait.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

char* tokens[256];

int tokenize(char* buf){
	int token_count=0;
	tokens[token_count]=strtok(buf," ");
	while(tokens[token_count] != NULL){
	tokens[token_count++]=strtok(NULL," ");
	}
	return token_count;
}

int main(){
	char line[1024];
	char* tokens[256];
	int token_num;
	char AllPath[1024];
	char* modified_path;
	char find_path[1024];
	pid_t pid;
	printf("enter quit to exit\n");

	while(1){
	printf("SISH %s@%s:",getenv("USER"),getenv("PWD"));
	fgets(line,sizeof(line),stdin);
	
	token_num=0;
	tokens[token_num]=strtok(line,"    \n");
	
	while(1){
	if(tokens[token_num] == NULL) break;
	token_num++;
	tokens[token_num]=strtok(NULL,"    \n");
	}
	if(strcmp(tokens[0],"quit")==0){printf("quit exit\n");exit(0);}
	
	strcpy(AllPath,getenv("PATH"));
	modified_path=strtok(AllPath,":");
	strcpy(find_path,modified_path);
	strcat(find_path,"/");
	strcat(find_path,tokens[0]);
	strcat(find_path,"");

	pid=fork();
	if(pid==-1){printf("error");exit(1);}
	else if (pid==0){
		while(1){
			if(execve(find_path,tokens,NULL) !=-1)break;
			modified_path=strtok(NULL,":");
			if(modified_path==NULL)break;
			strcpy(find_path,modified_path);
			strcat(find_path,"/");
			strcat(find_path,tokens[0]);
			strcat(find_path,"");
		}exit(1);
	}
	else{wait(&pid);}
	}
	return 0;

}




