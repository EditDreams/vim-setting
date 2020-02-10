/*================================================================
*   
*   项目名称：排序算法
*   文件名称：sort.c
*   创 建 者：Huangdatian
*   创建日期：2020年02月06日16:31:35
*   描    述: 冒泡、插入、选择、快速、希尔排序、归并排序。
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
	case 'h':
		ShellSort(arr,SIZE);
		Print(arr);
		break;
	case 'm':
		{
			int *pszTemp=NULL;
			pszTemp=(int*)malloc(sizeof(arr));
			MergeSort(arr,pszTemp,0,SIZE-1);
			Print(arr);
			free(pszTemp);
		}
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
int* ShellSort(int arr[],int len)
{
	int i,j;
	int gap=len/2;//间距
	while(gap>=1)
	{
		for(i=gap;i<len;++i)
		{
			int temp=arr[i];
			j=i-gap;
			while(j>=0&&temp<arr[j])//把i依次插入到前面有序中
			{
				arr[j+gap]=arr[j];
				j-=gap;
			}
			arr[j+gap]=temp;
		}
		gap/=2;//缩小间距
	}
	return  arr;
}
//分
void MergeSort(int arr[],int szTemp[],int left,int right)
{
	int mid=0;
	if(left<right)
	{
		mid=right+((left-right)>>2);
		MergeSort(arr,szTemp,left,mid);
		MergeSort(arr,szTemp,mid+1,right);
		Merge(arr,szTemp,left,mid,right);
	}
}
//治
void Merge(int arr[],int szTemp[],int left,int mid,int right)
{
	int tmp=0;
	int i=left;
	int j=mid+1;
	while(i<=mid&&j<=right)
	{
		if(arr[i]<=arr[j])
			szTemp[tmp++]=arr[i++];
		else
			szTemp[tmp++]=arr[j++];
	}
	while(i<=mid)
		szTemp[tmp++]=arr[i++];
	while(j<=right)
		szTemp[tmp++]=arr[j++];
	tmp=0;
	while(left<=right)
		arr[left++]=szTemp[tmp++];
}
void Print(int arr[])
{
	for(int i=0;i<SIZE;++i)
		printf("%d ",arr[i]);
	printf("\n");
}
