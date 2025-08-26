#include<stdio.h>
// power of 2 and 4 examples
int main()
{
	int var;// 0 1 0 0  // 16   0 0 0 1 0 0 0 0
	int cnt=0,i,j=31;
	printf("enter data:\n");
	scanf("%d",&var);
	while(var)
	{
		if((var>>j &1)==1)// checking the bit position which is set from left side
		{
			break;
		}
		else
			j--;
	}	 
	for(i=j;i>=0;i--)// assigining that value to index i
	{
		if(((var>>i)&1)==0)
		{
			cnt++;
		}
	}
	printf("%d\n",cnt);
	if((cnt%2==0) && ((var & var-1)==0))
	{
		printf("power of 4\n");
	}
	else
		printf("not\n");
}
