#include <bits/stdc++.h>
#include <pthread.h>
#include <semaphore.h>
#define bufferSize 10
#define noOfCosumers 5
#define noOfProducers 5
using namespace std;

sem_t full;
sem_t empty;
sem_t mutex;
int front;
int rear;
int arr[bufferSize];
void *produce(void* args){
	int pr = *((int*)(args));
	int pn=3;
	while(pn--){
	sem_wait(&empty);
	sem_wait(&mutex);
	int x=rand()%50;
	arr[rear]=x;
	printf("%d Wrote : %d\n",pr,x);
	rear=(rear+1)%bufferSize;
	sem_post(&mutex);
	sem_post(&full);
}
}


void *consume(void *args){
	int cm=*((int*)(args));
	int pn=3;
	while(pn--){
		sem_wait(&full);
		sem_wait(&mutex);
		int rd= arr[front];
		front=(front+1)%bufferSize;
		printf("%d read %d\n",cm,rd);
		sem_post(&mutex);
		sem_post(&empty);
	}
}


int main(int argc, char const *argv[])
{
	sem_init(&empty,0,bufferSize);
	sem_init(&full,0,0);
	sem_init(&mutex,0,1);

	pthread_t producer[noOfProducers];
	pthread_t consumer[noOfCosumers];

	int pr[noOfProducers],cm[noOfCosumers];


	for(int i=0;i<noOfProducers;i++){
		pr[i]=i+1;
		pthread_create(&producer[i],NULL,produce,pr+i);
	}

	for(int i=0;i<noOfCosumers;i++){
		cm[i]=i+1;
		pthread_create(&consumer[i],NULL,consume,cm+i);
	}

	for(int i=0;i<noOfProducers;i++)
	{
		pthread_join(producer[i],NULL);
	}

	for(int i=0;i<noOfCosumers;i++)
	{
		pthread_join(consumer[i],NULL);
	}

	return 0;
} 


