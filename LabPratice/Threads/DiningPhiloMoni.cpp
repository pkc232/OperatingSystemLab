#include <bits/stdc++.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/types.h>
#include <semaphore.h>
using namespace std;
sem_t mutex;
sem_t self[5];
enum e{Thinking,Eating,Hungry};
e state[5];
void test(int i){
	if(state[(i+4)%5]!=Eating&&state[(i+1)%5]!=Eating&&state[i]==Hungry){
		sem_post(&self[i]);
		state[i]=Eating;
		printf("%d is eating\n",i);
	}
}
void putdown(int i){
	sem_wait(&mutex);
	state[i]=Thinking;
	printf("%d has ate\n",i);
	test((i+4)%5);
	test((i+1)%5);
	sem_post(&mutex);
}

void pickup(int i){
	sem_wait(&mutex);
	printf("%d is Hungry\n",i);
	state[i]=Hungry;
	test(i);
	if(state[i]!=Eating)
		sem_wait(&self[i]);
	sem_post(&mutex);
	putdown(i);
}



void *philo(void *p){
	int i=(*((int*)p));
	while(1)
	{
	pickup(i);
	sleep(2);
} 
}
int main(int argc, char const *argv[])
{
	pthread_t pid[5];
	int arr[5];
	sem_init(&mutex,0,1);
	// Monitor m;
	for(int i=0;i<5;i++){
		arr[i]=i;
		state[i]=Thinking;
		sem_init(&self[i],0,1);
	}

	for(int i=0;i<5;i++){
		pthread_create(&pid[i],NULL,philo,(void*)(arr+i));
	}

	for(int i=0;i<5;i++){
		pthread_join(pid[i],NULL);
	}
	return 0;
}