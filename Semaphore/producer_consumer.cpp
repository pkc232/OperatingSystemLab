#include <bits/stdc++.h>
#include <sys/types.h>
#include <unistd.h>
#include <semaphore.h>
using namespace std;

#define SIZE 5
#define NUMB_THREADS 6
#define PRODUCER_LOOPS 2


int buffer[SIZE];
int buffer_index;

pthread_mutex_t buffer_mutex;

sem_t full_sem;
sem_t empty_sem;

void *insertbuffer(int value){
	if(buffer_index<SIZE){
		buffer[buffer_index++]=value;
	}
	else
	{
		printf("Buffer OVerflow \n");
	}
}

int dequeuebuffer(){
	if(buffer_index>0){
		return buffer[--buffer_index];
	}
	else
	{
		printf("BUffer Underflow\n");
	}
	return 0;

}

void *producer(void *thread_n){
	int thread_num=*(int*)thread_n;
	int value;
	int i=0;
	while(i++<PRODUCER_LOOPS){
		sleep(rand()%10);
		value=rand()%100;
		sem_wait(&full_sem);
		pthread_mutex_lock(&buffer_mutex);
		insertbuffer(value);
		pthread_mutex_unlock(&buffer_mutex);
		sem_post(&empty_sem);
		printf("Producer %d added %d to buffer\n",thread_num,value );
	}
	pthread_exit(0);
}

void *consumer(void *thread_n){
	int thread_num=*(int*)thread_n;
	int value,i=0;
	while(i++<PRODUCER_LOOPS){
		sem_wait(&empty_sem);
		pthread_mutex_lock(&buffer_mutex);
		value=dequeuebuffer();
		pthread_mutex_unlock(&buffer_mutex);
		sem_post(&full_sem);
		printf("consumer %d dequeued %d from buffer\n",thread_num,value );
	}
	pthread_exit(0);

}

int main(){
	buffer_index=0;
	pthread_mutex_init(&buffer_mutex,NULL);
	sem_init(&full_sem,0,SIZE);
	sem_init(&empty_sem,0,0);
	pthread_t thread[NUMB_THREADS];
	int thread_numb[NUMB_THREADS];
	int i;
	srand(time(NULL));
	for(i=0;i<NUMB_THREADS;){
		thread_numb[i]=i;
		pthread_create(&thread[i],NULL,producer,thread_numb+i);
		i++;
		thread_numb[i]=i;
		pthread_create(&thread[i],NULL,consumer,thread_numb+i);
		i++;
	}
	for(i=0;i<NUMB_THREADS;i++)
		pthread_join(thread[i],NULL);
	pthread_mutex_destroy(&buffer_mutex);
	sem_destroy(&full_sem);
	sem_destroy(&empty_sem);
	return 0;

}