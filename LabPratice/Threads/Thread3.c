#include <pthread.h>
#include <bits/stdc++.h>
int fl=1;

void* calculate(void *args){
	float *arr=new float[100]
	int i;
	for(i=0;i<100;i++)
	{
		arr[i]=(sqrt(i));
	}
	fl=1;
	return (void*)(arr);
}


int main(){
	pthread_t tid;

	void* exitStatus;
	pthread_create(&tid,NULL,calculate,NULL);
	while(fl){
		printf("Calculating\n");
	}
	pthread_join(tid,&exitStatus);

	float* arr=(float*)(exitStatus);
	int i;
	for(i=0;i<100;i++)
		printf("%f\n",arr[i]);

	return 0;



}