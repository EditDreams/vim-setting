/*********************************************************
*项目：   贪吃蛇(控制台)——（可运行）没完成有时间再修改
*@authorQQ：1105403369
**********************************************************/
#include<iostream>
//#include<Windows.h>   //Sleep(1000);
#include<conio.h>       //kbhit
#include<Windows.h>     //MessageBox
#include<time.h>        //srand
//#include<stdio.h>
#define RAW 20
#define COL 50
size_t length = 0;      //蛇的节数
using std::cout;
using std::endl;
enum Dir{ up = 119, down = 115, left = 97, right = 100 };
enum { space, wall, _snake, _food };
struct point
{
	int x, y;
};
typedef struct snake
{
	point position;     //坐标
	size_t value;       //枚举值
	enum Dir dir;       //方向
	size_t log;         //第几节蛇
	struct snake *pNext;
}*pSnake,Snake;
typedef struct food
{
	point position;
	bool has;
}*pFood;
//地图
void drawMap(int map[][COL]);
void printMap(int map[][COL]);
void changeMap(int map[][COL], pSnake head);
//蛇
pSnake initSnake();
void moveSnake(int map[][COL],pSnake head);
void changeSnake(int map[][COL], pSnake head);
void clearSnake(int map[][COL], pSnake head);
void insertSnake(pSnake head);
void freeSnake(pSnake head);
//食物
pFood createFood();
void eatFood(int map[][COL], pFood food, pSnake head);
//结束游戏
int gameOver(int map[][COL],pSnake head);

int main()
{
	srand((unsigned)time(NULL));
	//画出二维地图
	int map[RAW][COL];
	//goto语句返回到这里
	begin:
	//创建蛇身  链表——实现蛇身长度
	pSnake head = initSnake();
	//创建食物
	pFood temp_food = createFood();
	//画地图
	drawMap(map);
	while (true)
	{
		while (!kbhit())
		{
			changeMap(map, head);
			printMap(map);
			moveSnake(map, head);
			//每走一步将尾部一个擦除
			clearSnake(map, head);
			//吃到食物
			eatFood(map, temp_food, head);
			//判断游戏结束
			if (0 == gameOver(map, head))
			{
				system("cls");
				//释放蛇身内存 delete
				freeSnake(head);
				goto begin;
			}
			system("cls");
		}
		changeSnake(map, head);
	}
	return 0;
}
pSnake initSnake()
{
	pSnake temp = new snake;
	temp->value = _snake;
	temp->dir = right;
	temp->position.x = 5;
	temp->position.y = 5;
	temp->log = 1;           //第一节蛇身
	temp->pNext = NULL;
	length += 1;
	return temp;
}
void drawMap(int map[][COL])
{
	//画出二维地图
	for (int i = 0; i<RAW; ++i)
	{
		for (int j = 0; j<COL; ++j)
		{
			if (i == 0 || j == 0 || i == RAW-1 || j == COL-1)
			{
				map[i][j] = wall;// 1
			}	
			else
				map[i][j] = space;// 0
		}
	}

}
void printMap(int map[][COL])
{
	//地图边界
	for (int i = 0; i<RAW; ++i)
	{
		for (int j = 0; j<COL; ++j)
		{
			switch (map[i][j])
			{
			case wall:
				cout << "*";
				break;
			case space:
				cout << " ";
				break;
			case _snake:
				cout << "O";
				break;
			case _food:
				cout << "1";
				break;
			}
		}
		cout << endl;
	}
}
void changeMap(int map[][COL],pSnake head)
{
	map[head->position.x][head->position.y] = _snake;
}
void moveSnake(int map[][COL], pSnake head)
{
	switch (head->dir)
	{
	case up:
		head->position.x -= 1;
		break;
	case down:
		head->position.x += 1;
		break;
	case left:
		head->position.y -= 1;
		break;
	case right:
		head->position.y += 1;
		break;
	}
}
void changeSnake(int map[][COL], pSnake head)
{
	switch (getch())
	{
	case up:
		head->dir = up;
		break;
	case down:
		head->dir = down;
		break;
	case left:
		head->dir = left;
		break;
	case right:
		head->dir = right;
		break;
	}
}
void clearSnake(int map[][COL], pSnake head)
{
	pSnake p = head;
	//找蛇尾
	while (NULL != p->pNext)
	{
		p = p->pNext;
	}
	switch (p->dir)//一节蛇身可以执行
	{
	case up:
		map[p->position.x + 1][p->position.y] = space;
		break;
	case down:
		map[p->position.x - 1][p->position.y] = space;
		break;
	case left:
		map[p->position.x][p->position.y + 1] = space;
		break;
	case right:
		map[p->position.x][p->position.y - 1] = space;
		break;
	}

}
void insertSnake(int map[][COL], pSnake head)//此函数在eatFood函数中调用
{
	pSnake temp_head = new snake;
	temp_head->dir=head->dir;
	temp_head->log = head->log + 1;
	temp_head->position.x = head->position.x;
	temp_head->position.y = head->position.y;
	moveSnake(map, temp_head);
	temp_head->value = _snake;
	temp_head->pNext = NULL;
	length += 1;
	//头插
	temp_head->pNext = head->pNext;
	head->pNext = temp_head;
}
pFood createFood()
{
	pFood temp_food = new food;
	temp_food->position.x = rand() % 15 + 5;//这个范围是为了增加游戏体验
	temp_food->position.y = rand() % 45 + 5;
	temp_food->has = 1;
	return temp_food;
}
void eatFood(int map[][COL], pFood temp_food, pSnake head)
{

	if (true == temp_food->has)//true表示要创建一个食物
	{
		temp_food->position.x = rand() % 20 + 1;
		temp_food->position.y = rand() % 50 + 1;
		map[temp_food->position.x][temp_food->position.y] = _food;
		temp_food->has = false;
	}
	if (head->position.x == temp_food->position.x&&head->position.y == temp_food->position.y)
	{
		map[temp_food->position.x][temp_food->position.y] = space;
		temp_food->has = true;
		insertSnake(map, head);
	}
}
int gameOver(int map[][COL], pSnake head)
{
	if (head->position.x == 0 || head->position.x == RAW - 1 || head->position.y == 0 || head->position.y == COL - 1)
	{   //不知道哪里修改了??，这里要head->position.x == 0 和head->position.y == 0 
		cout << "\nx=" << head->position.x << "\ty=" << head->position.y;
		size_t recv = MessageBox(NULL, L"你选择了撞墙！在来一局吗？", L"游戏结束", MB_OKCANCEL);
		if (recv == IDOK)
		{
			return 0;
		}
		else //感觉这里代码逻辑有问题
		{
			exit(1);
		}
	}
}
void freeSnake(pSnake head)
{
	pSnake p = head, q;
	while (NULL != p)
	{
		q = p->pNext;
		delete p;
		p = q;
	}
	p = NULL;
	q = NULL;
} 