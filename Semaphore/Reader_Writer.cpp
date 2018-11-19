#include <bits/stdc++.h>
#include <sys/types.h>
#include <unistd.h>
#include <semaphore.h>
#define NUM 5
using namespace std;

sem_t wrt;
sem_t mutex;
int read_cnt=0;
int buffer;


void *write(void *n){
	int num=(*(int*)n);
	int value;
	sem_wait(&wrt);
	value=rand()%100;
	buffer=value;
	cout<<"Writer "<<num<<" wrote "<<value<<endl;
	sem_post(&wrt);
}

void *read(void *n){
	int num=(*(int*)n);

	sem_wait(&mutex);
	read_cnt++;
	if(read_cnt==1)
		sem_wait(&wrt);

	sem_post(&mutex);

	cout<<"Reader "<<num<<" read "<<buffer<<endl;

	sem_wait(&mutex);
	read_cnt--;

	if(read_cnt==0)
		sem_post(&wrt);

	sem_post(&mutex);


}

int main(){
	sem_init(&wrt,0,1);
	sem_init(&mutex,0,1);
	
	pthread_t writer[NUM];
	pthread_t reader[NUM];
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
}