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
void merge(int arr[], int left, int mid, int right)
{
	//creating temp arrays for left and right first calculate the size
	int s1=mid-left+1;
	int s2=right-mid;
	int l[s1],r[s2];
	// copying data into it.
	int i,j;
	for(i=0;i<s1;i++)
	{
		l[i]=arr[left+i];
	}
	for(j=0;j<s2;j++)
	{
		r[j]=arr[mid+j+1];
	}
	i=0,j=0;
	int k=left;
	//comparing and copying elements back to main array
	while(i<s1 && j < s2)
	{
		if(l[i]<= r[j])
		{
			arr[k++]=l[i++];
		}
		else
		{
			arr[k++]=r[j++];
		}

	}
	while(i<s1)
	{
		arr[k++]=l[i++];
	}
	while(j<s2)
	{
		arr[k++]=r[j++];
	}

}
void merge_sort(int arr[], int left, int right)
{
	if(left<right)
	{
		int mid=left+(right-left)/2;
		merge_sort(arr, left, mid);
		merge_sort(arr, mid+1, right);
		merge(arr, left, mid, right);
	}
}
int main()
{
	int arr[]={3,6,2,4,5,1};
	int s=sizeof(arr)/sizeof(arr[0]);
	int i=0;
	merge_sort(arr, 0, s-1);
	for(i=0;i<s;i++)
	{
		printf("%d ",arr[i]);
	}
}	
