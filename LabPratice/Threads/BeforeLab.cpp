#include <bits/stdc++.h>
#include <pthread.h>
using namespace std;

void* fun(void *p){
	int *x=(int*)(p);
	printf("%d\n",(*x));
}

int main(){
	pthread_t tid;
	int z=4;
	pthread_create(&tid,NULL,fun,(void*)(&z));
	pthread_join(tid,0);
}