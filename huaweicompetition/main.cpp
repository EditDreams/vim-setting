/*================================================================ *   
*   项目名称：初赛
*   文件名称：main.cpp
*   创 建 者：Huangdatian
*   创建日期：2020年04月20日10:33:39
*   描    述：
*
================================================================*/


#include "main.h"


int main()
{
//	pnode pHead=InitNode();//单链用于保存交换后的数据

//	InputFileData(pHead);
	
//	PrintNode(pHead);

	MyStack<pnode> mystack;
	MyTree<size_t_32> mytree;
	mytree.BParentInsertNode(1);//插入环的第一个
	mytree.CParentInsertNode(10);//插入环的第二个节点
	mytree.BrotherInsertNode(101);//插入当前节点环的brother
	mytree.CParentInsertNode(12);
	mytree.BrotherInsertNode(121);
	mytree.ChildInsertNode(122);//插入当前节点的child
	mytree.BrotherInsertNode(1210);

	mytree.BParentInsertNode(3);
	mytree.CParentInsertNode(31);
	mytree.CParentInsertNode(32);

	mytree.BParentInsertNode(6);
	mytree.CParentInsertNode(61);

	mytree.BParentInsertNode(9);
	mytree.CParentInsertNode(91);
	mytree.CParentInsertNode(10);
	
	mytree.Find();

	return 0;
}
void ProcessingData(pnode pHead,MyTree<size_t_32> &mytree)
{
	//深度寻路
	pnode p=pHead;
	pnode parentNode;
	pnode currentNode;
	pnode searchNode=pHead->m_pNext;
	//栈 存储走过的路径
	MyStack<pnode> mystack;
	//树 存储成环的数据
	while(p->m_pNext!=nullptr)//遍历所有路径中环的第一个点
	{
		parentNode=p->m_pNext;
		currentNode=p->m_pNext;
		mystack.PushStack(parentNode);
		++count;
		//找首尾相接的数据
		while(searchNode->m_pNext!=nullptr)
		{
			if(searchNode->m_data.m_current == currentNode->m_data.m_target)
			{
				currentNode=searchNode->m_pNext;//把找到的节点给当前节点
				mystack.PushStack(currentNode);
				++count;
				searchNode=pHead->m_pNext;//从头再找current
			}
			else
			{
				if(cout==1)//一个首尾相接的数据都没有
				{
					mystack.PopStack();
					currentNode=mystack.GetTopStack();
				}
				searchNode=searchNode->m_pNext;
			}
		}

		p=p->m_pNext;
	}
}
void PrintNode(pnode pHead)
{
	pnode p=pHead->m_pNext;
	while(p->m_pNext!=nullptr)
	{
		cout<<p->m_data.m_current<<' '
			<<p->m_data.m_target<<' '
			<<p->m_data.m_money<<'\n';
		p=p->m_pNext;
	}
}
void InputFileData(pnode pHead)
{
	ifstream readFile(filePath,std::ios::out);
	if(!readFile){
		cerr<<"error:test_data.txt open failed.\n";
		exit(1);
	}
	//读到char里面
	size_t_32 number=0;
	char pBuff[BUFFSIZE];
	int buffLength=0;
	size_t_32 pos=0; //区分三个数值
	size_t_32 i;
	size_t_32 j;
	size_t_32 current=0;
	size_t_32 target=0;
	size_t_32 money=0;
	MyStack<char> mystack; //数据转换临时存储区
	while(!readFile.eof())
	{
		readFile.getline(pBuff,BUFFSIZE);
		buffLength=strlen(pBuff);
		pos=0;
		for(i=0;i<buffLength;++i)
		{
			number=pBuff[i];
			if(number<=57 && number>=48)
			{
				mystack.PushStack(pBuff[i]);
			}
			else
			{
				size_t_32 sum=0;
				size_t_32 temp=0;
				for(j=1;!mystack.IsEmptyStack();j*=10)
				{
					temp=(mystack.GetTopStack()-48)*j;
					mystack.PopStack();
					sum+=temp;
				}
				++pos;
				switch(pos)
				{
					case 1:
						current=sum;
						break;
					case 2:
						target=sum;
						break;
					case 3:
						money=sum;
						break;
				}
			}
		}
		InsertNode(pHead,current,target,money);
	}
	readFile.close();
}
void InsertNode(pnode pHead,size_t_32 current,size_t_32 target,size_t_32 money)
{
	pnode temp=new node;
	temp->m_data.m_current=current;
	temp->m_data.m_target=target;
	temp->m_data.m_money=money;
	temp->m_pNext=nullptr;

	pnode p=pHead;
	while(p->m_pNext!=nullptr)
	{
		p=p->m_pNext;
	}
	p->m_pNext=temp;
}
pnode InitNode()
{
	pnode temp=new node;
	temp->m_pNext=nullptr;
	return temp;
}


