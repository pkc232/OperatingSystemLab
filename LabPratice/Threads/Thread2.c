#include <pthread.h>
#include <unistd.h>
#include <stdio.h>


void* printFun(void *args){
	int *p=(int*)(args);
	int i;
	for(i=1;i<=5;i++)
	printf("Hello, World thread %d\n",(*p));

	return NULL;
}


int main(){
	pthread_t tid[10];

	int num[10];int i;
	for(i=0;i<10;i++){
		num[i]=i;
		pthread_create(&tid[i],NULL,printFun,(void*)(num+i));
	}

	for(i=0;i<10;i++)
		pthread_join(tid[i],0);
	return 0;
}