#include <bits/stdc++.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/types.h>
#include <semaphore.h>
using namespace std;
int val=0;
int readCnt=0;
sem_t mutex,wrt;

void* readF(void* p){
	int x=(*((int*)p));
	while(true)
	{
	sem_wait(&mutex);
		readCnt++;
	if(readCnt==1)
		sem_wait(&wrt);
	sem_post(&mutex);

	printf("Reader %d read %d\n",x,val);

	sem_wait(&mutex);
	readCnt--;
	if(readCnt==0)
		sem_post(&wrt);
	sem_post(&mutex);
	sleep(1);
	// pthread_exit(0);
}
}

void* writeF(void* p){
	while(1)
	{
	sem_wait(&wrt);
	val=rand()%20+1;
	printf("Wrote %d\n",val);
	sem_post(&wrt);
	sleep(2);
	// pthread_exit(0);
}
}

int main(){
	int num=4;
	pthread_t reader[num],writer[num];

	int rd[num],wt[num];

	sem_init(&mutex,1,1);
	sem_init(&wrt,1,1);

	for(int i=0;i<num;i++){
		rd[i]=i;
		wt[i]=i;
		pthread_create(&reader[i],NULL,&readF,(&(rd[i])));
		pthread_create(&writer[i],NULL,&writeF,(&(wt[i])));
	}

	for(int i=0;i<num;i++)
	{
		pthread_join(reader[i],NULL);
		pthread_join(writer[i],NULL);
	}


}