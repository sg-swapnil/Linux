#include<stdio.h>
#include<stdlib.h>
//selection sort - we can select min or max index to compare and sort array
/*void selection_sort(int *arr,int s)
{
	int i,j,t,min;
	for(i=0;i<s-1;i++)
	{
		min=i;
		for(j=i+1;j<s;j++)
		{
			if(arr[j]<arr[min])
			{
				min=j;
			}
			else
			{
				continue;
			}
		}
		t=arr[i];
		arr[i]=arr[min];
		arr[min]=t;
	}
}
int main()
{
	int arr[]={3,5,1,2,4};
	int s=sizeof(arr)/sizeof(arr[0]);
	selection_sort(arr,s);
	int i;
	for(i=0;i<s;i++)
	{
		printf("%d",arr[i]);
	}
}
*/
// insertion sort
/*void insertion_sort(int *arr,int s)
{
	int i,key=0;
	for(i=1;i<s;i++)
	{
		key=arr[i];
		int j=i-1;
		//comparison
		while(j>=0 && key<arr[j])
		{
			arr[j+1]=arr[j];// shifting to right side
			j--;// decrementing j
		}
		arr[j+1]=key;//adding the key element in right position
	}
}
int main()
{
	int arr[]={3,5,1,2,4};
	int s=sizeof(arr)/sizeof(arr[0]);
	insertion_sort(arr,s);
	for(int i=0;i<s;i++)
	{
		printf("%d ",arr[i]);
	}
}*/
//quick sort

/*void swap(int *a,int *b)
{
	int t;
	t=*a;
	*a=*b;
	*b=t;
}
int partition(int *arr, int start, int end)
{
	int pivot=arr[end];//picking pivot
	int p_index=start;
	int i;
	for(i=start;i<end;i++)//0 4
	{
		if(arr[i]<pivot)// comparing it with other elements
		{
			swap(&arr[i],&arr[p_index]);
			p_index++;
		}
	}
	if(start<end)
	{
		swap(&arr[i],&arr[p_index]);//swapping last element i.e pivot
	}
	return p_index;
}
void quick_sort(int *arr, int start, int end)
{
	int p_index;
	if(start<end)
	{
		p_index=partition(arr, start, end);
		quick_sort(arr,start, p_index-1);
		quick_sort(arr,p_index+1,end);
	}
}
int main()
{
	int arr[]={3,5,1,2,4};
	int s=sizeof(arr)/sizeof(arr[0]);
	int start=0,end=s-1;
	quick_sort(arr,start,end);
	for(int i=0;i<s;i++)
	{
		printf("%d ",arr[i]);
	}
}
*/
void merge(int *arr, int *left, int mid,int *right,int end)
{
	int i=0,j=0,k=0;
	while(i<mid && j < end)
	{
		if(left[i]<right[j])
		{
			arr[k++]=left[i++];
		}
		else
		{
			arr[k++]=right[j++];
		}

	}
	while(i<mid)
	{
		arr[k++]=left[i++];
	}
	while(j<end)
	{
		arr[k++]=right[j++];
	}

}
void merge_sort(int *arr, int size)
{
	int i,mid,*left,*right;
	if(size<2)
	{
		return;
	}
	mid=size/2;
	left=malloc(mid* sizeof(int));
	right=malloc((size-mid)*sizeof(int));
	for(i=0;i<mid;i++)
	{
		left[i]=arr[i];
	}
	for(i=mid;i<size;i++)
	{
		right[i-mid]=arr[i];
	}
	merge_sort(left,mid);
	merge_sort(right,size-mid);
	merge(arr,left,mid,right,size-mid);
}
int main()
{
	int arr[]={3,6,2,4,5,1,8,7};
	int s=sizeof(arr)/sizeof(arr[0]);
	int i;
	merge_sort(arr,s);
	for(i=0;i<s;i++)
	{
		printf("%d ",arr[i]);
	}
}	
