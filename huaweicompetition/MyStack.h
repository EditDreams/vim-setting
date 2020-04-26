/*================================================================
*   
*   项目名称：MyStack.h
*   文件名称：MyStack.h
*   创 建 者：Huangdatian
*   创建日期：2020年04月20日10:33:56
*   描    述：出栈、入栈、栈顶、栈是否为空（单链表）
*
================================================================*/

#pragma once

template<typename T>
class MyStack
{
public:
	MyStack();
	~MyStack();
	void PopStack();
	void PushStack(const T& pushData);
	T GetTopStack();
	bool IsEmptyStack();
private:
	struct mynode
	{
		T m_data;
		mynode* m_pNext;
	};
	typedef mynode* pMynode;
	pMynode pHead;
};

template<typename T>
bool MyStack<T>::IsEmptyStack()
{
	return pHead->m_pNext==nullptr;
}
template<typename T>
T  MyStack<T>::GetTopStack()
{
	return pHead->m_pNext->m_data;
}
template<typename T>
void MyStack<T>::PushStack(const T& pushData)
{
	pMynode temp=new mynode;
	temp->m_data=pushData;
	temp->m_pNext=nullptr;
	//头插
	temp->m_pNext=pHead->m_pNext;
	pHead->m_pNext=temp;
}
template<typename T>
void MyStack<T>::PopStack()
{
	pMynode p=pHead->m_pNext;
	pMynode temp=p->m_pNext;
	delete p;
	p=temp;
	pHead->m_pNext=p;
}
template<typename T>
MyStack<T>::~MyStack()
{
	//delete pHead;
	pMynode p=pHead->m_pNext;
	pMynode temp;
	while(p!=nullptr)
	{
		temp=p->m_pNext;
		delete p;
		p=temp;
	}
	delete pHead;
	pHead->m_pNext=nullptr;
}
template<typename T>
MyStack<T>::MyStack()
{
	pHead=new mynode;
	pHead->m_pNext=nullptr;
}

