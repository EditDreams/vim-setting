/*================================================================
*   
*   项目名称：排序算法
*   文件名称：sort.c
*   创 建 者：Huangdatian
*   创建日期：2020年02月06日16:31:35
*   描    述：尽可能全面的演示所有排序算法的代码实例。
*
================================================================*/


#include"sort.h"

int main(int argc,char* argv[])
{
	int arr[SIZE]={5,8,7,6,9,1,2,3,4,0};
	char *p=argv[1];
	switch(*p)
	{
	case 'b':
		BubbleSort(arr,SIZE);
		Print(arr);
		break;
	case 's':
		SelectSort(arr,SIZE);
		Print(arr);
		break;
	case 'i':
		InsertSort(arr,SIZE);
		Print(arr);
		break;
	case 'f':
		FastSort(arr,0,SIZE-1);
		Print(arr);
		break;
	default:
		printf("参数错误.\n");
		break;
	}
	return 0;
}

int* BubbleSort(int arr[],int size)
{
	int i=0,j=0;
	for(;i<	size-1;++i)
	{
		for(j=0;j<size-i-1;++j)
		{
			if(MAX(arr[j],arr[j+1])==arr[j])
				SWAP(arr[j],arr[j+1]);
		}
	}
	return arr;
}
int* SelectSort(int arr[],int size)
{
	int i=0,j=0;
	for(;i<size-1;++i)
	{
		for(j=i+1;j<size;++j)
		{
			if(MAX(arr[i],arr[j])==arr[i])
				SWAP(arr[i],arr[j]);
		}
	}
	return arr;
}
int* InsertSort(int arr[],int size)
{
	int i=0,j=0,z=0;
	int temp=0;
	for(;i<size-1;++i)
	{
		temp=arr[i+1];
		for(j=0;j<=i;++j)
		{
			if(MAX(arr[j],temp)==arr[j])
				break;
		}
		for(z=i;z>=j;--z)//移动数组腾出插入的空位
			arr[z+1]=arr[z];
		arr[j]=temp;
	}
	return arr;
}
void FastSort(int arr[],int left,int right)
{
	int i=left,j=right;
	if(left>=right)return;//排除不符合left<right规则的情况
	while(i<j)
	{
		while(i<j&&arr[j]>=arr[left])--j;//右边找一个小的值
		while(i<j&&arr[i]<=arr[left])++i;
		if(i<j)
			SWAP(arr[i],arr[j]);
	}
	//SWAP(arr[left],arr[j]);
	int temp=arr[left];
	arr[left]=arr[j];
	arr[j]=temp;

	FastSort(arr,left,j-1);
	FastSort(arr,j+1,right);
}
void Print(int arr[])
{
	for(int i=0;i<SIZE;++i)
		printf("%d ",arr[i]);
	printf("\n");
}
