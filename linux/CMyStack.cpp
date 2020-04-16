/***************************************
*深度优先搜索实现迷宫寻路 main.cpp
**************************************/
#include<iostream>   
#include<Windows.h>   
#include"CMyStack.h"       
#define ROW  25	//地图行数 Y       
#define COL  25	//地图列数 X   
#define SPEED 1	//刷新速度         

struct MyPoint{
	int row;
	int col;
};
enum MyDir{ UP, DOWN, LEFT, RIGHT };	//表示方向的枚举   
struct MyPath{
	int  val;
	MyDir dir;
	bool isFind;
};
void drawMap(int map[ROW][COL], MyPoint point){
	system("cls");
	for (int i = 0; i < ROW; i++){
		for (int j = 0; j < COL; j++){
			if (map[i][j] == 1){//墙   
				std::cout << "□";
			}
			else if (point.row == i && point.col == j)
			{//人   
				std::wcout << "我";
			}
			else{//路   
				std::wcout << "  ";
			}
		}
		std::cout << std::endl;
	}
	Sleep(SPEED);
}
int main()
{
	//地图 0:路 1:墙   
	int map[ROW][COL] = {
		{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1 },
		{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 0, 1 },
		{ 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 1, 0, 1 },
		{ 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 0, 1 },
		{ 1, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1 },
		{ 1, 0, 1, 1, 1, 1, 0, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1 },
		{ 1, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1 },
		{ 1, 0, 1, 0, 1, 1, 0, 1, 0, 1, 0, 0, 0, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 0, 1 },
		{ 1, 0, 1, 0, 0, 0, 0, 1, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1 },
		{ 1, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1 },
		{ 1, 0, 0, 0, 1, 0, 0, 0, 0, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1 },
		{ 1, 1, 1, 0, 1, 1, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1 },
		{ 1, 0, 1, 0, 0, 0, 0, 1, 0, 1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1 },
		{ 1, 0, 1, 1, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1 },
		{ 1, 0, 1, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 0, 1, 0, 1, 0, 1 },
		{ 1, 0, 1, 0, 1, 1, 1, 1, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1 },
		{ 1, 0, 0, 0, 1, 0, 0, 0, 0, 1, 1, 0, 1, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 1 },
		{ 1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 0, 0, 1, 0, 0, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1 },
		{ 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
		{ 1, 0, 1, 1, 1, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1 },
		{ 1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1, 1, 1, 1, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 1 },
		{ 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 0, 0, 1, 0, 1, 1, 0, 1, 0, 1, 0, 1, 1, 1 },
		{ 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1 },
		{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 }
	};
	//画一个二维标记数组   
	MyPath pathMap[ROW][COL];
	for (int i = 1; i < ROW - 1; i++)
	{
		for (int j = 1; j < COL - 1; j++)
		{
			pathMap[i][j].val = map[i][j]; //地图值   
			pathMap[i][j].dir = RIGHT;     //所有起点默认从右先开始找   
			pathMap[i][j].isFind = false;  //标记没走过   
		}
	}
	//设置起点和终点   
	MyPoint beginPos = { 1, 1 };
	MyPoint endPos = { 9, 1 };//1,23   
	CMyStack<MyPoint> myStack;    
	myStack.PushStack(beginPos);
	//当前节点   
	MyPoint currentPos;
	MyPoint searchPos = beginPos;
	//死循环一个节点一个节点走动   
	while (1){
		//找到终点   
		if (searchPos.row == endPos.row &&searchPos.col == endPos.col)
		{
			std::cout << "找到终点啦!";   
				break;
		}
		currentPos = searchPos;
		switch (pathMap[searchPos.row][searchPos.col].dir)
		{
		case RIGHT:
			currentPos.col++;
			pathMap[searchPos.row][searchPos.col].dir = DOWN;
			if (pathMap[currentPos.row][currentPos.col].val == 0 &&
				pathMap[currentPos.row][currentPos.col].isFind == false)
			{
				pathMap[currentPos.row][currentPos.col].isFind = true;    
				myStack.PushStack(currentPos);
				searchPos = currentPos;
			}
			break;
		case DOWN:
			currentPos.row++;
			pathMap[searchPos.row][searchPos.col].dir = LEFT;
			if (pathMap[currentPos.row][currentPos.col].val == 0 &&
				pathMap[currentPos.row][currentPos.col].isFind == false)
			{
				pathMap[currentPos.row][currentPos.col].isFind = true;
				myStack.PushStack(currentPos);
				searchPos = currentPos;
			}
			break;
		case LEFT:
			currentPos.col--;
			pathMap[searchPos.row][searchPos.col].dir = UP;
			if (pathMap[currentPos.row][currentPos.col].val == 0 &&
				pathMap[currentPos.row][currentPos.col].isFind == false)
			{
				pathMap[currentPos.row][currentPos.col].isFind = true;
				myStack.PushStack(currentPos);
				searchPos = currentPos;
			}
			break;
		case UP:
			currentPos.row--;
			if (pathMap[currentPos.row][currentPos.col].val == 0 &&
				pathMap[currentPos.row][currentPos.col].isFind == false)
			{
				pathMap[currentPos.row][currentPos.col].isFind = true;
				myStack.PushStack(currentPos);
				searchPos = currentPos;
			}
			else
			{
				myStack.PopStack();
				searchPos = myStack.GetTopStack();
			}
			break;
		}
		//没找到出口   
		if (myStack.IsEmptyStack())
		{
			std::cout << "这个迷宫没有出口!";//栈空->回到原点   
				break;
		}
		drawMap(map, searchPos);//每循环一次刷新一次     
	}
	//打印路径   
	while (!myStack.IsEmptyStack())
	{
		currentPos = myStack.GetTopStack();
		char *p;
		switch (pathMap[currentPos.row][currentPos.col].dir)
		{
		case UP:
			p = "左";
			break;
		case DOWN:
			p = "右";
			break;
		case LEFT:
			p = "下";
			break;
		case RIGHT:
			p = "上";
			break;
		}
		std::cout << "(" << currentPos.row << "," << currentPos.col << "," << p << ")";
		myStack.PopStack();
	}
	return 0;
}
