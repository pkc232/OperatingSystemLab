#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
 
int n;

void *fibo(void *vargp){
	int i;
	int dp[1000];
	dp[1]=1;
	dp[2]=1;

	for(i=3;i<=n;i++)
			dp[i]=dp[i-1]+dp[i-2];
	for(i=1;i<=n;i++)
		printf("%d ", dp[i]);
	printf("\n");
}

int main(int argc,char *argv[])
{
    pthread_t tid;
    int i;
    n=atoi(argv[1]);
    
    printf("Before Thread\n");
    pthread_create(&tid, NULL, fibo, NULL);
    pthread_join(tid, NULL);
    printf("After Thread\n");
    exit(0);
}