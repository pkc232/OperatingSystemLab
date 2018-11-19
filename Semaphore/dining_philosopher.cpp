#include <bits/stdc++.h>
#include <sys/types.h>
#include <semaphore.h>
#include <unistd.h>
using namespace std;


sem_t chopstick[5];

void* philosopher(void *n){
	int num=(*(int*)n),i=0;
	while(i++<3)
	{
	sem_wait(&chopstick[num]);
	sem_wait(&chopstick[(num+1)%5]);

	printf("philosopher %d picked \n",num);

	sem_post(&chopstick[num]);
	sem_post(&chopstick[(num+1)%5]);
	
}
pthread_exit(0);
}

int main(){
	for(int i=0;i<5;i++)
	sem_init(&chopstick[i],0,1);
	
	pthread_t philo[5];
	int p[5];
	for(int i=0;i<5;i++)
	{
		p[i]=i;
		pthread_create(&philo[i],NULL,philosopher,p+i);
	}


	for(int i=0;i<5;i++){
		pthread_join(philo[i],NULL);
	}
}

