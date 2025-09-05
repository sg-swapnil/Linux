#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
#include<semaphore.h>
//binary semaphore
int rel=0;
sem_t bin_sem;
pthread_t t[4];
int id[4];
void* thread_fun(void* arg)
{
        int i,id= *(int*)arg;
       	printf("thread %d waiting..\n",id);
	sem_wait(&bin_sem);
	printf("thread %d entered into critical section:\n",id);
        for(int i=0;i<50;i++)
        {
                rel+=i;
		sleep(0.91);
        }
	printf("thread %d leaving..\n",id);
	sem_post(&bin_sem);
        return NULL;
}
int main()
{
//	pthread_t t[4];
	sem_init(&bin_sem,0,1);
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

	sem_destroy(&bin_sem);
}
