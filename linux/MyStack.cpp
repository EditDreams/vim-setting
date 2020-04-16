/**************************************************
作者：          黄达添
功能:           用面向过程的方法实现栈的基本操作
最后修改日期:    2019年3月22日
***************************************************/
#include<iostream>
typedef struct stack
{
	int data;
	struct stack *pNext;
}*pMyStack,MyStack;

void push_stack(pMyStack head,int data);
void pop_stack(pMyStack head);
int top_stack(pMyStack head);
int length_stack(pMyStack head);
void destory_stack(pMyStack head);
bool isEmpty(pMyStack head);
void show_stack(pMyStack head);

int main()
{
	pMyStack head = new MyStack;//栈顶
	head->pNext = NULL;
	for (size_t i = 0; i < 10; ++i)
	{
		push_stack(head, i);
	}
	show_stack(head);
	std::cout << "\n出栈之后：\n";
	pop_stack(head);
	show_stack(head);
	//destory_stack(head);
	if (false == isEmpty(head))//栈是否为空 否flase  是true
	{
		std::cout << "栈不为空。\n";
	}
	else
	{
		std::cout << "栈为空\n";
	}
	return 0;
}
void push_stack(pMyStack head, int data)
{ 
	pMyStack temp = new MyStack;
	temp->data = data;
	temp->pNext = NULL;

	temp->pNext = head->pNext;
	head->pNext = temp;
}
void pop_stack(pMyStack head)
{
	pMyStack p = head->pNext;
	pMyStack temp = p->pNext;
	free(p);
	p = temp;
	head->pNext = p;
}
int top_stack(pMyStack head)
{
	return head->pNext->data;
}
int length_stack(pMyStack head)
{
	int length = 0;
	pMyStack p = head->pNext;
	while (NULL != p)
	{
		length++;
		p = p->pNext;
	}
	return length;
}
void destory_stack(pMyStack head)
{
	pMyStack p = head->pNext,q;
	while (NULL != p)
	{
		q = p->pNext;
		free(p);
		p = q;
	}
	free(head);
	head->pNext = NULL;
}
bool isEmpty(pMyStack head)
{
	return head->pNext == NULL;
}
void show_stack(pMyStack head)
{
	pMyStack p = head->pNext;
	while (NULL != p)
	{
		std::cout << p->data << "->";
		p = p->pNext;
	}
} 