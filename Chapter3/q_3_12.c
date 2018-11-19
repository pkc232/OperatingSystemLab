#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>

int value=6;

int main(){
	pid_t pid=fork();

	if(pid==0){
		value+=15;
		return 0;
	}
	else if(pid>0){
		wait(NULL);
		printf("Parent : value=%d\n",value);
		return 0;
	}
}