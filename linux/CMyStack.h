/***********************************
*单链表实现栈的基本功能 CMyStack.h
**********************************/
#pragma once    
template<typename T>
class CMyStack
{
public:
	CMyStack();
	~CMyStack();
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
CMyStack<T>::CMyStack()
{
	m_pHead = new MyNode;
	//m_pHead->m_Data = 0;    
	m_pHead->m_pNext = nullptr;
}
template<typename T>
CMyStack<T>::~CMyStack()
{
	MyNode* p = m_pHead->m_pNext, *q;
	while (NULL != p)
	{
		q = p->m_pNext;
		delete p;
		p = q;
	}
	delete m_pHead;
	m_pHead->m_pNext = NULL;
}
template<typename T>
void CMyStack<T>::PushStack(const T& kData)
{
	MyNode* temp = new MyNode;
	temp->m_Data = kData;
	temp->m_pNext = NULL;
	temp->m_pNext = m_pHead->m_pNext;
	m_pHead->m_pNext = temp;
}
template<typename T>
void CMyStack<T>::PopStack()
{
	MyNode* p = m_pHead->m_pNext;
	MyNode* temp = p->m_pNext;
	delete p;
	p = temp;
	m_pHead->m_pNext = p;
}
template<typename T>
T CMyStack<T>::GetTopStack()
{
	MyNode* p = m_pHead->m_pNext;
	return p->m_Data;
}
template<typename T>//链表中没有元素就为空    
bool CMyStack<T>::IsEmptyStack()
{
	return m_pHead->m_pNext == nullptr;
	//如果是nullptr返回true    
}