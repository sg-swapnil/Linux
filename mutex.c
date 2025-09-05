#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
#include<semaphore.h>
//creating multiple threads checking the result by sharing global variable to each thread, then applying mutex for proper result
int rel=0;
pthread_mutex_t lock;
pthread_t t[4];
int id[4];
void* thread_fun(void* arg)
{
        pthread_mutex_lock(&lock);
        int id= *(int*)arg;
	printf("thread %d is in critical section:\n",id);
        for(int i=0;i<100;i++)
        {
                rel+=i;
		sleep(0.001);// if we did't add sleep it might show correct result without adding mutex its base on system scheduling..
        }
        pthread_mutex_unlock(&lock);
        return NULL;

}
int main()
{
        pthread_mutex_init (&lock,NULL);
        int i;
        for(i=0;i<4;i++)
        {
 		id[i]=i;
		pthread_create(&t[i], NULL,thread_fun, &id[i]);
        }
        for(i=0;i<4;i++)
        {
                pthread_join(t[i], NULL);
        }
	printf("result:%d\n",rel);
}
