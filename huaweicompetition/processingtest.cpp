/*================================================================
*   
*   项目名称：processinttest.cpp
*   文件名称：processinttest.cpp
*   创 建 者：Huangdatian
*   创建日期：2020年04月24日20:09:38
*   描    述：
*
================================================================*/


#include<iostream>
#include "MyStack.h"
#include "MyTree.h"
struct node
{
	int m_x;
	int m_y;
	node* m_pNext;
};
typedef node* pnode;
void InsertNode(pnode pHead,int x,int y)
{
	pnode temp=new node;
	temp->m_x=x;
	temp->m_y=y;
	temp->m_pNext=nullptr;;

	pnode p=pHead;
	while(p->m_pNext!=nullptr)
	{
		p=p->m_pNext;
	}
	p->m_pNext=temp;
}
void PrintNode(pnode pHead)
{
	pnode p=pHead->m_pNext;
	while(p!=nullptr)
	{
		std::cout<<p->m_x<<' '<<p->m_y<<'\n';
		p=p->m_pNext;
	}
}
int main()
{
	pnode pHead=new node;
	pHead->m_pNext=nullptr;

	InsertNode(pHead,1,2);
	InsertNode(pHead,1,3);
	InsertNode(pHead,2,4);
	InsertNode(pHead,3,4);
	InsertNode(pHead,4,1);
	InsertNode(pHead,2,5);
	InsertNode(pHead,5,4);
	InsertNode(pHead,4,6);
	InsertNode(pHead,6,7);
	InsertNode(pHead,7,4);
	
	//PrintNode(pHead);
	
	//环的路径
	int count=0;
	MyStack<pnode> mystack;

	pnode parent;
	pnode current;
	pnode search;

	pnode p=pHead->m_pNext;
	while(p!=nullptr)
	{
		count=0;
		parent=p;
		current=p;
		mystack.PushStack(current);
		++count;
		search=p->m_pNext;
		while(search!=nullptr)
		{
			if(current->m_y==search->m_x)
			{
				if(count<7)
				{
					std::cout<<"parent"<<parent->m_x<<' '<<parent->m_y<<"  ";
					std::cout<<"current"<<current->m_x<<' '<<current->m_y<<"-> ";
					std::cout<<"search"<<search->m_x<<' '<<search->m_y<<'\n';
				}
				current=search;
				mystack.PushStack(current);
				++count;
				search=pHead;
				search=search->m_pNext;
				if(current==parent)//找到环就退栈，回到上一层
				{
					mystack.PopStack();
					--count;
					search=mystack.GetTopStack();
					search=search->m_pNext;
					mystack.PopStack();
					--count;
					current=mystack.GetTopStack();
					std::cout<<"栈顶:"<<current->m_x<<' '<<current->m_y<<"  栈大小："<<count+2<<'\n';
					std::cout<<"--------------------------------------------\n";
				}
				if(count>7)//路径大于7的去掉
				{
					mystack.PopStack();
					--count;
					search=mystack.GetTopStack();
					search=search->m_pNext;
					mystack.PopStack();
					--count;
					current=mystack.GetTopStack();
					int gdb=0;
				}
				int gdb=1;
				if(search->m_pNext==nullptr&&count!=1)
				{
				}
			}
			else
				search=search->m_pNext;
		}
		p=p->m_pNext;
	}
	return 0;
}
