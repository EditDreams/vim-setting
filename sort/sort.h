/*================================================================
*   
*   项目名称：排序算法
*   文件名称：sort.h
*   创 建 者：Huangdatian
*   创建日期：2020年02月06日16:31:43
*   描    述：sort.c头文件
*
================================================================*/


#include<stdio.h>
#include<stdlib.h>
#define SIZE 10 //要排序的数组大小
#define MAX(a,b) ((a)>(b))?(a):(b)
#define SWAP(a,b) (a)=(a)+(b),(b)=(a)-(b),(a)=(a)-(b)//交换两个数的值

void Print(int arr[]);
int* BubbleSort(int arr[],int size);
int* SelectSort(int arr[],int size);
int* InsertSort(int arr[],int size);
void FastSort(int arr[],int left,int right);
