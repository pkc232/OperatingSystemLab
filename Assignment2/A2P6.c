#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>


int sum=0,n,p;
struct range
{
	/* data */
	int lo;
	int hi;
};

void *addfact(void *v){
	struct range temp=(*(struct range*)v);
	int i=temp.lo,j=temp.hi;
	while(i<=j){
		if(n%i==0)
			sum+=i;
		i++;
	}
}


int main(int argc,char *argv[])
{
    
    int i,j,k;
     n=atoi(argv[1]);
     p=atoi(argv[2]);
	
	pthread_t tid[p];
	int prtsz=n/p;
	struct range arr[p];
	i=0,j=1;
	while(i<p){
		arr[i].lo=1+i*prtsz;
		arr[i].hi=arr[i].lo+prtsz;
		pthread_create(&tid[i], NULL, addfact, (void*)&arr[i]);
		i++;
	}
	i=0;
	while(i<p){
		pthread_join(tid[i], NULL);
		i++;
	}
	//printf("%d is sum\n",sum);    
	sum-=n;
	if(sum==n)
		printf("%d is a perfect number\n",n);
	else
		printf("%d is not a perfect number\n",n);
    printf("After Thread\n");
    exit(0);
}