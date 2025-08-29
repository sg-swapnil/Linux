#include<stdio.h>
#include<stdlib.h>
int main()
{
	int var=0b00001100;// 0000 1100
	int i,sum=0;
	for(i=0;i<=7;i++)
	{
		if((var>>i)&1)
		{
			sum=sum+(1<<i);// here taking power of 2
			//printf("%d ",i);
		}
		//printf("%d ",(var>>i)&1);
	}
	printf("%d",sum);
	printf("\n");
}
