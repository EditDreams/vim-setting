/*================================================================
*   Copyright (C) 2019 * Ltd. All rights reserved.
*
*   File name   : singal_list.c
*   Author      : mabu
*   QQ          : 1105403369
*   Created date: 2019-10-27 20:01:43
*   Description : 实现单向链表的增、删、查、改、排序
*				（最后修改时间：2019-12-16 18:07:06）
*===============================================================*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct node
{
	int data;
	struct node* pNext;
}*pNode, Node;
int headIsNull = 1;

pNode InitNode();
void InsertNode(pNode head, int data);
void FindNode(pNode head, int data);
void ModifyNode(pNode head, int oldData, int newData);
pNode DeleteNode(pNode head, int delData);
void SortNode(pNode head);
void FreeNode(pNode head);
void PrintNode(pNode head);

int main(int argc, char *argv[])
{
	pNode head = InitNode();
	//插入
	int listSize;
	printf("请输入链表大小：\n");
	scanf("%d",&listSize);
	for (int i = 0; i<listSize; ++i)
	{
		int num;
		printf("请输入要插入的数据：\n");
		scanf("%d",&num);
		InsertNode(head, num);
	}
	PrintNode(head);
	//查找
	int findNum;
	printf("请输入你要查找的数据：\n");
	scanf("%d",&findNum);
	FindNode(head, findNum);
	PrintNode(head);
	//修改
	int newData, oldData;
	printf("请输入你要修改的数字和修改后的数据：\n");
	scanf("%d%d",&oldData,&newData);
	ModifyNode(head, oldData, newData);
	PrintNode(head);
	//删除
	int delData;
	printf("请输入要删除的数：\n");
	scanf("%d",&delData);
	head=DeleteNode(head, delData);
	int stop=0;
	PrintNode(head);
	//排序
	printf("开始排序：\n");
	SortNode(head);
	PrintNode(head);
	//释放所有内存
	FreeNode(head);
	return 0;
}
pNode InitNode()
{
	pNode tmp = (pNode)malloc(sizeof(Node));
	tmp->pNext = NULL;
	return tmp;
}
void InsertNode(pNode head, int data)
{
	if (headIsNull == 1)
	{
		head->data = data;
		headIsNull = 0;
	}
	else
	{
		pNode p = head;
		while (p->pNext != NULL)
			p = p->pNext;
		pNode temp = (pNode)malloc(sizeof(Node));
		temp->data = data;
		temp->pNext = NULL;
		p->pNext = temp;
	}
}
void FindNode(pNode head, int data)
{
	pNode p = head;
	while (p->pNext)
	{
		if (p->data == data)
		{
			printf("数据查找到了:%d",p->data);
			printf("\n");
			return;
		}
		else
			p = p->pNext;
	}
	if (p->data == data)
	{
		printf("数据查找到了:%d",p->data);
		printf("\n");
		return;
	}
	printf("抱歉，没有你要查找的数据!\n");
}
void ModifyNode(pNode head, int oldData, int newData)
{
	pNode p = head;
	while (p->pNext)
	{
		if (p->data == oldData)
		{
			p->data = newData;
			printf("数据修改成功!\n");
			return;
		}
		else
			p = p->pNext;
	}
	if (p->data == oldData)
	{
		p->data = newData;
		printf("数据修改成功!\n");
		return;
	}
	printf("抱歉，没有找到你要修改的数据！\n");
}
pNode DeleteNode(pNode head, int delData)
{
	pNode p = head;
	//判断当前要删除的数据是不是头结点
	if (delData == p->data)
	{
		head = p->pNext;
		free(p);
		p = NULL;
		printf("删除数据成功！\n");
		return head;
	}
	while (p->pNext)
	{
		if (p->pNext->data == delData)
		{
			pNode tmp = p->pNext;
			p->pNext = tmp->pNext;
			free(tmp);
			tmp = NULL;
			printf("数据删除成功！\n");
			return head;
		}
		else
			p = p->pNext;
	}
	printf("抱歉，没有找到你要删除的数据！\n");
	return head;
}
void SortNode(pNode head)
{
	pNode p = head;
	pNode tmp=NULL,q=NULL;
	int position = 0;
	while (p->pNext)
	{
		++position;
		p = p->pNext;
	}
	++position;
	p = head;
	for (int i = 0; i<position - 1; ++i)
	{
		tmp = p->pNext;
		for (int j = i + 1; j<position; ++j)
		{
			if (p->data>tmp->data)
			{ 
			 	q = (pNode)malloc(sizeof(Node));
				q->data = p->data;
				p->data = tmp->data;
				tmp->data = q->data;
				free(q);
				q=NULL;
			}
			tmp = tmp->pNext;
		}
		p = p->pNext;
	}
}
void FreeNode(pNode head)
{
	pNode p=head;
	while(p)
	{
		pNode temp=p->pNext;
		free(p);
		p=temp;
	}
}
void PrintNode(pNode head)
{
	pNode p = head;
	while (p->pNext)
	{
		printf("%d->",p->data);
		p = p->pNext;
	}
	printf("%d",p->data);
	printf("\n");
}