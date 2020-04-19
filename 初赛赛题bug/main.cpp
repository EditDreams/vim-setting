/*================================================================
*   
*   项目名称：main.cpp
*   文件名称：main.cpp
*   创 建 者：Huangdatian
*   创建日期：2020年04月15日09:40:36
*   描    述：
*
================================================================*/


#include<iostream>
#include<fstream>
#include<string.h>
#include "MyStack.h"
using std::ifstream;
using std::ofstream;
using std::cerr;
using std::streamoff;
using std::cout;
using std::string;
#define BUFFSIZE 18
struct data		//存储读入的每一条数据
{
	size_t m_current;	//当前顶点标号
	size_t m_target;	//目标顶点标号
	size_t m_pay;		//转账金额
};
typedef data* pdata;
struct node
{
    data m_data;
    node* m_pNext;
};
typedef node* pnode;

pnode InitNode();
void InputFile(pnode pHead);
void InsertNode(pnode pHead,char pBuff[]);
void PrintNode(pnode pHead);
void ProcessingData(pnode pHead);
void Find(pnode pCurrent,pnode pHead,size_t count,size_t pathLength,
        MyStack<pnode> & buffStack);
int main(void)
{
    pnode pHead=InitNode();
	InputFile(pHead);
	return 0;
}
void Find(pnode pCurrent,pnode pHead,size_t count,size_t pathLength,
        MyStack<pnode> & buffStack)
{
    //当前节点的target和下一个节点的current依次比较
    size_t temp=pCurrent->m_data.m_target;
    pnode pSearch=pHead->m_pNext;
    while(pCurrent->m_pNext!=nullptr)
    {
        while(pSearch->m_pNext!=nullptr)
        {
            //区间判断
            /*if(pathLength<=7&&pathLength>=3)
            {
                ++count;
            }
            else
            {
                buffStack.PopStack();
                --pathLength;
                pSearch=buffStack.GetTopStack();
            }*/
            if(temp==pSearch->m_data.m_current)//首尾相接
            {
                //符合首尾相接的都进栈先
                buffStack.PushStack(pSearch);
                ++pathLength;
                //递归下一层
                //Find(pSearch,pHead,count,pathLength,buffStack);
            }
            
            cout<<"pCurrent:"<<pCurrent->m_data.m_current<<' '
                <<pCurrent->m_data.m_target<<'\n';
            cout<<"pSearch:"<<pSearch->m_data.m_current<<' '
                <<pSearch->m_data.m_target<<'\n';

            pSearch=pSearch->m_pNext;
        }
        cout<<"pCurrent:\n";
        pCurrent=pCurrent->m_pNext;
    }
    cout<<"finished\n";
}
void ProcessingData(pnode pHead)
{
    //深度寻路
    MyStack<pnode> buffStack;
    pnode p=pHead->m_pNext;
    buffStack.PushStack(p);
    size_t count=0;     //环的个数
    size_t pathLength=0;//路径的长度
    Find(p,pHead,count,pathLength,buffStack);
}
void PrintNode(pnode pHead)
{
    pnode p=pHead->m_pNext;
    size_t i;
    for(i=1;p->m_pNext!=nullptr;)
    {
        cout<<p->m_data.m_current
            <<'\t'<<p->m_data.m_target
            <<'\t'<<p->m_data.m_pay<<'\n';
        p=p->m_pNext;
        ++i;
    }
    cout<<p->m_data.m_current
        <<'\t'<<p->m_data.m_target
        <<'\t'<<p->m_data.m_pay<<'\n';
}

void InsertNode(pnode pHead,char pBuff[])
{
	pnode dataLine=new node;
    dataLine->m_pNext=nullptr;

	string strLine;
	strLine.assign(pBuff);

	size_t pos=0;//区分三个数值的标记
	size_t number=0;
	//过滤逗号
	MyStack<char> mystack;
	size_t i,j;
	for(i=0;i<strLine.size();++i)
	{
		number=strLine[i];
		if(strLine[i]!=','&&number>=48&&number<=57)
		{
			mystack.PushStack(strLine[i]);
		}
		else
		{
			size_t sum=0,temp=0;
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
					dataLine->m_data.m_current=sum;;
					break;
				case 2:
					dataLine->m_data.m_target=sum;
					break;
				case 3:
					dataLine->m_data.m_pay=sum;
					break;
			}
		}
	}
    pnode p=pHead;
    while(p->m_pNext!=nullptr)
        p=p->m_pNext;
    pHead->m_pNext=dataLine;
}
void InputFile(pnode pHead)
{
	ifstream readFile("test_data.txt",std::ios::out|std::ios::ate);
	if(!readFile)
	{
		cerr<<"cerr:test_data.txt open failed.\n";
		exit(1);

    }

	//streamoff nSize=readFile.tellg();
	readFile.seekg(0,std::ios::beg);
	//cout<<"streamoff size:"<<nSize<<"\n";
	
	//转成string类型
	char pBuff[BUFFSIZE]={0};
	while(!readFile.eof())
    {
	    readFile.getline(pBuff,BUFFSIZE);   
        InsertNode(pHead,pBuff);
       // PrintNode(pHead);
       // ProcessingData(pHead);
    }
    PrintNode(pHead);
    ProcessingData(pHead);
	readFile.close();

}
pnode InitNode()
{
    pnode temp=new node;
    temp->m_pNext=nullptr;
    return temp;
}
