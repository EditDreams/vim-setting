/*================================================================
*   
*   项目名称：MyTree.h
*   文件名称：MyTree.h
*   创 建 者：Huangdatian
*   创建日期：2020年04月22日16:30:31
*   描    述：用于单链表遍历之后节点的存储，存储的是环
*   		  (单链表实现树)
*
================================================================*/


#pragma once
#include <iostream>
using std::cout;
template<typename T>
class MyTree
{
private:
	struct node
	{
		T m_data;
		node* m_pChild;
		node* m_pBrother;
	};
	typedef node* pnode;
	pnode pHead;//所有环的第一个元素的头
	pnode pBrotherCurrent;
	pnode pChildCurrent;
	int count=0;
public:
	MyTree();
	~MyTree();
	void BParentInsertNode(const T& headData);//根的儿子节点中插入兄弟节点（环的所有的头元素）
	void CParentInsertNode(const T& headData);//根的儿子节点中插入儿子节点
	void ChildInsertNode(const T& childData);//在当前节点插入儿子节点（保存所有环层数元素的链表）
	void BrotherInsertNode(const T& brotherData);//在当前节点插入兄弟节点
	void Find();
};
template<typename T>
void MyTree<T>::Find()//前根遍历 根左右
{
	if(pHead->m_pBrother==nullptr)
		return;
	pnode p=pHead;
	pnode pChild;
	pnode pSearch;
	while(p->m_pBrother!=nullptr)
	{
		cout<<p->m_pBrother->m_data<<' ';
		pSearch=p->m_pBrother;
		while(pSearch->m_pChild!=nullptr)
		{
			//找左孩子 一个环已经出来了
			pChild=pSearch->m_pChild;
			cout<<pChild->m_data<<' ';
			pSearch=pSearch->m_pChild;
			//
		}
		cout<<'\n';
		p=p->m_pBrother;
	}
}
template<typename T>
void MyTree<T>::BrotherInsertNode(const T& brotherData)//在当前节点插入兄弟节点
{
	pnode temp=new node;
	temp->m_data=brotherData;
	temp->m_pBrother=temp->m_pChild=nullptr;

	//if pBrotherCurrent==nullptr
	pnode p=pBrotherCurrent;
	while(p->m_pBrother!=nullptr)
	{
		p=p->m_pBrother;
	}
	p->m_pBrother=temp;
	pChildCurrent=p->m_pBrother;
	int gdb=0;
}
template<typename T>
void MyTree<T>::ChildInsertNode(const T& childData)//在每一个头元素下扩展一个环
{
	pnode temp=new node;
	temp->m_data=childData;
	temp->m_pChild=temp->m_pBrother=nullptr;

	pnode p=pChildCurrent;
	if(p->m_pChild==nullptr)
	{
		p->m_pChild=temp;
	}
	else
	{
		while(p->m_pChild!=nullptr)
		{
			p=p->m_pChild;
		}
		p->m_pChild=temp;
	}
	int gdb=0;
}
template<typename T>
void MyTree<T>::BParentInsertNode(const T& headData)
{
	//每次调用插入的是环的第一个元素
	pnode temp=new node;
	temp->m_data=headData;
	temp->m_pBrother=temp->m_pChild=nullptr;

	pnode p=pHead;
	while(p->m_pBrother!=nullptr)
	{
		p=p->m_pBrother;
	}
	p->m_pBrother=temp;
}
template<typename T>
void MyTree<T>::CParentInsertNode(const T& headData)
{
	pnode temp=new node;
	temp->m_data=headData;
	temp->m_pChild=temp->m_pBrother=nullptr;

	pnode p=pHead;//第几个环的头
	while(p->m_pBrother!=nullptr)//保证每次插入的位置都是最后头的位置
		p=p->m_pBrother;
	if(p->m_pChild==nullptr)
	{
		p->m_pChild=temp;
	}
	else
	{
		while(p->m_pChild!=nullptr)
		{
			p=p->m_pChild;
		}
		p->m_pChild=temp;
	}
	pBrotherCurrent=p->m_pChild;
	++count;
	int gdb=0;
}
template<typename T>
MyTree<T>::~MyTree()
{
	
}
template<typename T>
MyTree<T>::MyTree()
{
	pHead=new node;
	pHead->m_pBrother=pHead->m_pChild=nullptr;
	pChildCurrent=new node;
	pChildCurrent->m_pChild=pChildCurrent->m_pBrother=nullptr;
	pBrotherCurrent=new node;
	pBrotherCurrent->m_pBrother=pBrotherCurrent->m_pChild=nullptr;
}

