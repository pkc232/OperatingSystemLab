#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{
	pid_t pid;
	pid=fork();

	if(pid==0){
		execlp("/bin/ls","ls",NULL);
		printf("child complete\n");
	}
	else
	{
		wait(NULL);
		printf("Parent complete\n");
		exit(0);
	}
	return 0;
}