#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
int main(char *argv[]){
	int main(char *argv[]){}
	char* str[2];
	str[0]="/bin/sh";
	str[1]=NULL;
	while(1){
	printf("input path");
	scanf("%s",str[0]);
	execve(str[0],str,NULL);
	if(str[0] == "quit"){
	exit(0);
	}
	}
}
