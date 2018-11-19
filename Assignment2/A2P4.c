#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

int i=0,n=10;
char* Buffer;

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
void* Consumer(void* nums)
{
      while(1)
      {
            if(i==-1) sleep(10);
            pthread_mutex_lock(&mutex);            
       
            printf("Consumer Process:%d\n", --i);        
            pthread_mutex_unlock(&mutex);   
            sleep(2);     
      } 
      return NULL;   
}
 
void* Producer(void* nums)
{    
      while(1)
      { 
            if(i==n) sleep(10);
            pthread_mutex_lock(&mutex);

            Buffer[i] = 'A';
            printf("Producer Process:%d\n", i++);
            pthread_mutex_unlock(&mutex); 
            sleep(1);
      } 
      return NULL;   
}
 
int main(int argv,char** argc)
{
   pthread_t producer_thread,consumer_thread;
   Buffer=(char*)malloc(sizeof(char)*n);
   pthread_create(&producer_thread,NULL,Producer,NULL);
   pthread_create(&consumer_thread,NULL,Consumer,NULL);
   
   pthread_join(producer_thread,NULL);
   pthread_join(consumer_thread,NULL);
   exit(0);
   return 0;
}
   