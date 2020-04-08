#include <stdio.h>
#include <unistd.h>

int main(){
	int x;
	x=0;
	printf("fork start\n");
	fork();
	printf("fork end\n");
	
	x=1;
	printf("PID: %d, x:%d\n", getpid(), x);
	
	return 0;
}
