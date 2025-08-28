#include<stdio.h>
#include<stdint.h>// to add unsigned int datatype
int convert_lit_big(int var)
{

	union data{
		uint32_t num;
		uint8_t arr[4];//array of 4 integer each size is 8bits to access the 1byte at a time
	}src,des;
	src.num=var;
	des.arr[0]=src.arr[3];
	des.arr[1]=src.arr[2];
	des.arr[2]=src.arr[1];
	des.arr[3]=src.arr[0];
	return des.num;
}
int main()
{
	int var =0x12345678;
	int result=convert_lit_big(var);
	printf("little endian:0x%x\n",var);
	printf("big endian:0x%x\n",result);
}
