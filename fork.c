#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>

int main()
{
	printf("%d\n",getpid());//parent process
	pid_t pid = fork();
	if(pid==-1)
	{
		printf("fork failed\n");
	}
	else if(pid ==0)
	{
		printf("i am child process:%d\n",getpid());
		printf("child executing..\n");
	}
	else
	{
		printf("i am parent process:%d\n",getpid());
		wait(NULL);
		printf("child is finished:\n");
	}
}
