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
#define PREVSIZE 5
struct Datalist		//存储读入的每一条数据
{
	unsigned int current;	//当前顶点标号
	unsigned int target;	//目标顶点标号
	unsigned int pay;		//转账金额
};
typedef Datalist* pDatalist;

void InputFile()
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
	char pBuff[18]={0};
	string str_line;

	readFile.getline(pBuff,18);
	str_line.assign(pBuff);
	
	unsigned int pos=0;//区分三个数值的标记
	unsigned int number=0;
	//过滤逗号
	pDatalist dataline=new Datalist;
	CMyStack<char> mystack;
	int i,j;
	for(i=0;i<str_line.size();++i)
	{
		number=str_line[i];
		if(str_line[i]!=','&&number>=48&&number<=57)
		{
			mystack.PushStack(str_line[i]);
		}
		else
		{
			int sum=0,temp=0;
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
					dataline->current=sum;;
					break;
				case 2:
					dataline->target=sum;
					break;
				case 3:
					dataline->pay=sum;
					break;
			}
		}
	}
	
	cout<<"current:"<<dataline->current
		<<"  target:"<<dataline->target
		<<"  pay:"<<dataline->pay<<'\n';
	readFile.close();
}
int main(void)
{
	InputFile();
	return 0;
}


