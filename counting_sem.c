#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
#include<semaphore.h>
//counting semaphore
int rel=0;
sem_t cnt_sem;
pthread_t t[10];
int id[4];
#define MAX_RES 3
void* thread_fun(void* arg)
{
        int i,id= *(int*)arg;
       	printf("thread %d waiting..\n",id);
	sem_wait(&cnt_sem);
	printf("thread %d entered into critical section:\n",id);
        for(int i=0;i<50;i++)
        {
                rel+=i;
		sleep(0.9);
        }
	printf("thread %d leaving..\n",id);
	sem_post(&cnt_sem);
        return NULL;
}
int main()
{
//	pthread_t t[4];
	sem_init(&cnt_sem,0,MAX_RES);
        int result=0,i;
        for(i=0;i<4;i++)
        {
                id[i]=i;
		pthread_create(&t[i], NULL,thread_fun, &id[i]);
        }
        for(i=0;i<4;i++)
        {
                pthread_join(t[i], NULL);
        }
       	printf("rel:%d\n",rel);

	sem_destroy(&cnt_sem);
}
