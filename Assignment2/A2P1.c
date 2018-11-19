#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
 
// A normal C function that is executed as a thread when its name
// is specified in pthread_create()
double avg;
int arr[10];
int n;
void *sum(void *vargp){
	int s=0,i;
	for(i=0;i<n;i++)
		s+=arr[i];

	printf("Sum %d \n",s);
	avg=s/(double)n;
	printf("Avg %lf\n",avg);
}

void *maxm(void *vargp){
	int s=-99999,i;
	for(i=0;i<n;i++)
		if(arr[i]>s)
			s=arr[i];
	printf("Max %d \n",s);
}
void *minm(void *vargp){
	int s=99999,i;
	for(i=0;i<n;i++)
		if(arr[i]<s)
			s=arr[i];
	printf("Min %d \n",s);
}
  
int main(int argc,char *argv[])
{
    pthread_t tid;
    int i;
    n=argc-1;
    for(i=0;i<argc-1;i++){
    	arr[i]=atoi(argv[i+1]);
    	printf("%d ",arr[i]);
    }
    printf("Before Thread\n");
    pthread_create(&tid, NULL, sum, NULL);
    pthread_create(&tid, NULL, maxm, NULL);
    pthread_create(&tid, NULL, minm, NULL);
    pthread_join(tid, NULL);
    printf("After Thread\n");
    exit(0);
}