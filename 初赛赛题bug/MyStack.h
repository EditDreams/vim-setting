/*================================================================
*   
*   项目名称：MyStack.h
*   文件名称：MyStack.h
*   创 建 者：Huangdatian
*   创建日期：2020年04月15日14:53:13
*   描    述：单链表实现基本栈
*
================================================================*/
#pragma once
template<typename T>
class MyStack
{
public:
	MyStack();
	~MyStack();
	void PushStack(const T& kData);
	void PopStack();
	T    GetTopStack();
	bool IsEmptyStack();
private:
	struct MyNode
	{
		T         m_Data;
		MyNode *  m_pNext;
	};
	MyNode* m_pHead;
};
template<typename T>
MyStack<T>::MyStack()
{
	m_pHead = new MyNode;
	//m_pHead->m_Data = 0;    
	m_pHead->m_pNext = nullptr;
}
template<typename T>
MyStack<T>::~MyStack()
{
	MyNode* p = m_pHead->m_pNext, *q;
	while (nullptr != p)
	{
		q = p->m_pNext;
		delete p;
		p = q;
	}
	delete m_pHead;
	m_pHead->m_pNext = nullptr;
}
template<typename T>
void MyStack<T>::PushStack(const T& kData)
{
	MyNode* temp = new MyNode;
	temp->m_Data = kData;
	temp->m_pNext = nullptr;
	temp->m_pNext = m_pHead->m_pNext;
	m_pHead->m_pNext = temp;
}
template<typename T>
void MyStack<T>::PopStack()
{
	MyNode* p = m_pHead->m_pNext;
	MyNode* temp = p->m_pNext;
	delete p;
	p = temp;
	m_pHead->m_pNext = p;
}
template<typename T>
T MyStack<T>::GetTopStack()
{
	MyNode* p = m_pHead->m_pNext;
	return p->m_Data;
}
template<typename T>//链表中没有元素就为空    
bool MyStack<T>::IsEmptyStack()
{
	return m_pHead->m_pNext == nullptr;
	//如果是nullptr返回true    
}
