#include <bits/stdc++.h>
#include <pthread.h>
#include <semaphore.h>
#define num 5
using namespace std;

sem_t wrt;
sem_t mutex;

int readCnt=0;
int buffer=0;

void *write(void *args){
	int wr=*((int*)args);
	sem_wait(&wrt);
	sem_wait(&mutex);
	buffer=(rand()%10);
	printf("%d writer wrote %d\n",wr,buffer);
	sem_post(&wrt);
	sem_post(&mutex);
}

void *read(void *args){
	int rd = *((int*)args);

	sem_wait(&mutex);
	readCnt++;
	if(readCnt==1)
		sem_wait(&wrt);

	sem_post(&mutex);

	printf("%d reader read %d\n",rd,buffer);

	sem_wait(&mutex);
	readCnt--;
	if(readCnt==0)
		sem_post(&wrt);

	sem_post(&mutex);

}


int main(int argc, char const *argv[])
{
	sem_init(&wrt,0,1);
	sem_init(&mutex,0,1);

	pthread_t writer[num];
	pthread_t reader[num];
	int NUM=num;
		int W[NUM],R[NUM];

	for(int i=0;i<NUM;i++){
		W[i]=i;
		R[i]=i;
		pthread_create(&writer[i],NULL,write,W+i);
		pthread_create(&reader[i],NULL,read,R+i);
	}

	for(int i=0;i<NUM;i++){
		pthread_join(writer[i],NULL);
		pthread_join(reader[i],NULL);
	}


	return 0;
}