#include <bits/stdc++.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/types.h>
#include <semaphore.h>
using namespace std;
sem_t chopstick[5];

void* eat(void* p)
{

	int i=(*((int*)p));
	while(1){
	// sleep(1);
	sem_wait(&chopstick[i]);
	printf("%d philosopher picked up chopstick %d\n",i,i);
	sem_wait(&chopstick[(i+1)%5]);
	printf("%d philosopher picked up chopstick %d\n",(i+1)%5,(i+1)%5);
	printf("%d philosopher  \n",i);
	printf("%d is eating\n",i);
	sem_post(&chopstick[i]);
	printf("%d philosopher dropped chopstick %d\n",i,i);
	sem_post(&chopstick[(i+1)%5]);
	printf("%d philosopher dropped chopstick %d\n",(i+1)%5,(i+1)%5);
	// sleep(1);
	}
}


int main(int argc, char const *argv[])
{
	int num[5];
	pthread_t philo[5];
	for(int i=0;i<5;i++){
		sem_init(&chopstick[i],0,1);
		num[i]=i;
	}
	for(int i=0;i<5;i++){
		pthread_create(&philo[i],NULL,eat,(void*)(&num[i]));
	}
	for(int i=0;i<5;i++){
		pthread_join(philo[i],NULL);
	}


	return 0;
}