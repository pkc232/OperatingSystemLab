#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
int n;
int check(int x){
	int i;
	if(i==1)
		return 0;
	for(i=2;i<x;i++){
		if(x%i==0)
			return 0;
	}
	return 1;
}

void *prnt(void *vargp){
	int i;
	for(i=1;i<=n;i++)
		if(check(i))
			printf("%d ,",i);
}

int main(int argc,char *argv[])
{
    pthread_t tid;
    int i;
    n=atoi(argv[1]);
    
    printf("Before Thread\n");
    pthread_create(&tid, NULL, prnt, NULL);
    pthread_join(tid, NULL);
    printf("After Thread\n");
    exit(0);
}