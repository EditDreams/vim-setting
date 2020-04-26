/*================================================================
*   
*   项目名称：初赛
*   文件名称：main.h
*   创 建 者：Huangdatian
*   创建日期：2020年04月20日10:34:08
*   描    述：
*
================================================================*/

#pragma once

#include <iostream>
#include <fstream>
#include <string.h>
#include "MyStack.h"
#include "MyTree.h"
using std::ifstream;
using std::string;
using std::cerr;
using std::cout;
#define BUFFSIZE 32
typedef unsigned int size_t_32;
int count=0;//环路径的长度
const char* filePath="test_data.txt";

struct data
{
	size_t_32 m_current;
	size_t_32 m_target;
	size_t_32 m_money;
};
typedef data* pdata;
struct  node
{
	data m_data;
	node* m_pNext;
};
typedef node* pnode;

pnode InitNode();
void InsertNode(pnode pHead,size_t_32 current,size_t_32 target,size_t_32 money);
void InputFileData(pnode pHead);
void PrintNode(pnode pHead);

