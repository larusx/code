#include<stdio.h>
void Swap(int* a, int* b)
{
	int tmp=*a;
	*a=*b;
	*b=tmp;
}
void Qsort(int* arr, int n)
{
	if(n== 1 || n==0)
		return ;
	if(n == 2)
	{
		if(arr[0]>arr[1])
			Swap(&arr[0],&arr[1]);
	}
	int left=1;
	int right=n-1;
	int* val=&arr[0];
	while(left<right)
	{
		while(arr[right]>*val && right>=1)
			right--;
		if(right == 0)
			break;
		Swap(&arr[right],val);
		val=&arr[right];
		while(arr[left]<*val && left<=n-1)
			left++;
		if(left == n)
			break;
		Swap(&arr[left],val);
		val=&arr[left];
	}
	Qsort(&arr[0],val-&arr[0]);
	Qsort(val+1,&arr[n-1]-val);
}
void print(int* arr, int n)
{
	for(int i=0;i<n;i++)
		printf("%d ",arr[i]);
	printf("\n");
}
int main()
{
	int arr[]={-1,6,3,1,4,2,5,10};
	Qsort(arr,sizeof(arr)/sizeof(int));
	print(arr,sizeof(arr)/sizeof(int));
	return 0;
}
