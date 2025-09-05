#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
#include<semaphore.h>
//creating multiple threads checking the result by sharing global variable to each thread, then applying mutex for proper result
int rel=0;
pthread_mutex_t lock;
void* thread_fun(void* arg)
{
        pthread_mutex_lock(&lock);
        int num= *(int*)arg;
        for(int i=0;i<100;i++)
        {
                rel+=i;
        	printf("in thread_fun num:%d rel:%d\n",num,rel);
		sleep(0.001);// if we did't add sleep it might show correct result without adding mutex its base on system scheduling..
        }
        pthread_mutex_unlock(&lock);
        return NULL;

}
int main()
{
        pthread_t t[4];
        pthread_mutex_init (&lock,NULL);
        int a=1,result=0,i;
        for(i=0;i<4;i++)
        {
                pthread_create(&t[i], NULL,thread_fun, &a);
        }
        for(i=0;i<4;i++)
        {
                pthread_join(t[i], NULL);
        }
        for(i=0;i<4;i++)
        {
                result+=rel;
        //        printf("in for loop rel=%d\n",rel);
        }
	printf("final:%d\n",result);
}
