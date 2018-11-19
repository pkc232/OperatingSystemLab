#include <pthread.h>
#include <unistd.h>
#include <stdio.h>

void* func(void *args){
	int *p=(int*)(args);
	printf("%d\n",(*p));
}


int main(){
	pthread_t tid;
	int num=4;

	pthread_create(&tid,NULL,func,(void*)(&num));
	pthread_join(tid,0);
	return 0;
}