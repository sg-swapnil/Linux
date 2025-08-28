#include<stdio.h>
#include<ctype.h>// to check if digit present
int usr_atoi(char *str)
{
	int i=0,res=0,sign=1;
	while(*str==' ' || *str=='\t')
	{
		str++;
	}
	if(*str=='-')
	{
		sign=-1;
		str++;
	}
	else if(*str=='+')
	{
		sign=1;
		str++;
	}

	for(i=0;str[i]!='\0';i++)
	{
		res=res*10 + str[i]-'0';
	}
	return sign*res;
}
int main()
{
	char str[]="  -123";
	int result=usr_atoi(str);
	printf("%d\n",result);
}
