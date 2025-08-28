#include<stdio.h>
#include<stdlib.h>
//strcpy
/*char* usr_def_strcpy(char *des, const char *src)
{
	int i;
	for(i=0;src[i]!='\0';i++)
	{
		des[i]=src[i];
	}
	des[i]='\0';
	return des;
}

int main()
{
	char str[]="swapnil";
	char des[10];
	usr_def_strcpy(des,str);//no need to assign o/p of this function as we are copying the data to des so it will be same.
	printf("%s\n",des);
}
*/
//memcpy

/*char* usr_memcpy(char *des, const char *src, int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		des[i]=src[i];
	}
	des[i]='\0';
	return des;
}
int main()
{
	char str[]="swapnilgawai";
	char des[20];
	int n;
	printf("how many bytes to be copy:\n");
	scanf("%d",&n);
	usr_memcpy(des,str,n);
	printf("%s\n",des);
}
*/
//memmove

char* usr_memmove(char *des, const char *src, int n)
{
	//take care of overlapping in case of same buffer(string)
	char *temp=malloc(sizeof(n));// we can create char temp[size]
	int i;
	for(i=0;i<n;i++)
	{
		temp[i]=src[i];
	}
	for(i=0;i<n;i++)
	{
		des[i]=temp[i];
	}
	free(temp);
	return des;		
}
int main()
{
	char str[]="swapnil";
	//char des[20];
	int n;
	printf("how many bytes to be copy:\n");
	scanf("%d",&n);
	usr_memmove(str+2,str,n);
	printf("%s\n",str);
}
