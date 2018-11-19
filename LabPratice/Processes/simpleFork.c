#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>

int main(){
	pid_t p1,p2;
	p1=fork();
	if(p1<0){
		printf("fork failed\n");
		return 1;
	}
	else
	{
		if(p1==0){
			printf("child printed\n");
		}
		else{
			sleep(2);
			printf("parent printed\n");
		}
	}
}
