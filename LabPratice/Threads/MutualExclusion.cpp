#include <bits/stdc++.h>
#include <pthread.h>
#include <unistd.h>
using namespace std;

pthread_mutex_t lock;

int shared_data;

void *thread_function(void *args){
	int i;

	for(i=0;i<1000*1000;i++)
	{
		pthread_mutex_lock(&lock);
		shared_data++;
		pthread_mutex_unlock(&lock);
	}
	return NULL;
}


int main(){
	pthread_t tid;

	void *exit_status;

	int i;

	pthread_mutex_init(&lock,NULL);

	pthread_create(&tid,NULL,thread_function,NULL);

	for(i=0;i<10;i++){
		//sleep(1);
		//pthread_mutex_lock(&lock);
		printf("SHared value=%d\n",shared_data);
		//pthread_mutex_unlock(&lock);
	}

	pthread_join(tid,&exit_status);

	pthread_mutex_destroy(&lock);
	return 0;
}
