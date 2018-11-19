#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>


int main(int argc, char const *argv[])
{
	pid_t pid;
	pid=fork();
	if(pid==0){
		printf("idhr print karna\n");
	}
	return 0;
}

