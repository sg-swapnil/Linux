#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>

int main()
{
	printf("main/parent process:%d\n",getpid());
	pid_t pid=fork();
	if(pid==-1)
	{
		printf("fork failed:\n");
	}
	else if(pid==0)
	{
		printf("in child process:%d\n",getpid());
		execlp("ls","ls","-1",NULL);//execlp does't create new process it replace the current one without changing pid
	}
	else
	{
		printf("in parent process:%d\n",getpid());
		wait(NULL);
		printf("child finished:\n");
	}
}
