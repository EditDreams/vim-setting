#include<iostream>
#include<conio.h>
#include<graphics.h>
#include<time.h>
#define WIDTH 800	//窗口大小
#define HEIGHT 500
#define ROW 5		//图片被切的格数
#define COL 5
#define NUM 25		//产生随机数的数组大小
enum Dir { UP = 119, DOWN = 115, LEFT = 97, RIGHT = 100 };
typedef struct node
{
	int log;
	int src_x, src_y;
}Node;
typedef struct map
{
	int posLog;
	int pos_x, pos_y;
	int pic_x, pic_y;//直接把图片剪切的坐标保存在map里面
	bool notHavePic;
}Map;

//加载图片
IMAGE sbImg;


void InitGrap();
void MovePic(Map mapArr[][COL]);

int main()
{
	InitGrap();
	//左下角空格

	return 0;
}
void InitGrap()
{
	initgraph(WIDTH, HEIGHT);
	srand((unsigned)time(NULL));

	Map map[ROW][COL];
	memset(map, 0, sizeof(map));
	int tempLog = 0;				//给数组里面的位置做标记
	for (int i = 0; i < ROW; ++i)
	{
		for (int j = 0; j < COL; ++j)
		{
			map[i][j].posLog = tempLog;
			++tempLog;
		}
	}
	//左下角留空
	map[ROW - 1][0].notHavePic = true;

	//一张图片的结构体
	Node picArr[ROW][COL];
	int srcX = 0, srcY = 0;
	//设置背景图片
	setbkcolor(BLACK);

	//加载图片
	//IMAGE sbImg;
	loadimage(&sbImg, L"./spongeBaby.jpg", 500, 500, false);

	//剪切图片
	tempLog = 0;
	for (int i = 0; i < ROW; ++i)
	{
		for (int j = 0; j < COL; ++j, srcX += 100)
		{
			picArr[i][j].log = tempLog;		//标记加载的图片，图片id：0~24
			++tempLog;
			picArr[i][j].src_x = srcX;
			picArr[i][j].src_y = srcY;
		}
		srcX = 0;
		srcY += 100;
	}
	//创建产生随机数的数组0~24
	int randArr[NUM];
	for (int i = 0; i < NUM; ++i)
	{
		randArr[i] = i;
	}

	//遍历数组，给数组里面的每一个位置随机放一张图片
	int num = 25;
	int k;
	for (int i = 0; i < ROW; ++i)
	{
		for (int j = 0; j < COL; ++j)
		{
			int temp = rand() % num;
			map[i][j].posLog = randArr[temp];//地图数组位置随机抽取一张图片
			map[i][j].pos_x = picArr[i][j].src_x;//地图位置和图片刚裁剪的位置是一样的
			map[i][j].pos_y = picArr[i][j].src_y;
			//减去数组里面的数（每个随机数只适用一次）
			for (int n = 0; n < NUM; ++n)
			{
				if (randArr[n] == randArr[temp])
				{
					for (k = n; k < NUM - 1; ++k)
					{
						randArr[k] = randArr[k + 1];
					}
					break;
				}
			}
			--num;
		}
	}
	for (int i = 0; i < ROW; ++i)
	{
		for (int j = 0; j < COL; ++j)
		{
			//在图片数组里面找到和随机数相同的数
			for (int n = 0; n < ROW; ++n)
			{
				for (int m = 0; m < COL; ++m)
				{
					if (map[i][j].posLog == picArr[n][m].log)
					{
						if (false == map[i][j].notHavePic)//如果位置没有图片就放一张图片
						{
							map[i][j].pic_x = picArr[n][m].src_x;
							map[i][j].pic_y = picArr[n][m].src_y;
							putimage(map[i][j].pos_x, map[i][j].pos_y, 99, 99, &sbImg,
								map[i][j].pic_x, map[i][j].pic_y);
						}
					}
				}
			}
		}
	}

	//右边提示信息
	outtextxy(550, 10, L"海绵宝宝和派大星");
	IMAGE sbShowImg;
	loadimage(&sbShowImg, L"./spongeBaby.jpg", 200, 120, false);
	putimage(550, 50, &sbShowImg);

	//键盘按键控制
	MovePic(map);
	closegraph();
}
Node FindPosition(Map mapArr[][COL])
{
	//找空格
	Node mapLogTmp;
	for (int i = 0; i < ROW; ++i)
	{
		for (int j = 0; j < COL; ++j)
		{
			if (mapArr[i][j].notHavePic == true)
			{
				mapLogTmp.src_x = i;//保存空图在数组中下标的位置
				mapLogTmp.src_y = j;
			}
		}
	}
	return mapLogTmp;
}
void MovePic(Map mapArr[][COL])
{
	char ch;
	Node mapLog;
	while (1)
	{
		while (kbhit())
		{
			mapLog = FindPosition(mapArr);
			ch = _getch();
			switch (ch)
			{
			case UP:
				if (mapLog.src_x != ROW-1)//不是第一行(空格下一张往上移动)
				{
					//擦除下面
					clearrectangle(
						mapArr[mapLog.src_x + 1][mapLog.src_y].pos_x,
						mapArr[mapLog.src_x + 1][mapLog.src_y].pos_y,
						mapArr[mapLog.src_x + 1][mapLog.src_y].pos_x + 99,
						mapArr[mapLog.src_x + 1][mapLog.src_y].pos_y + 99);
					//要相应修改地图的空格的值
					mapArr[mapLog.src_x][mapLog.src_y].pic_x=mapArr[mapLog.src_x + 1][mapLog.src_y].pic_x;
					mapArr[mapLog.src_x][mapLog.src_y].pic_y = mapArr[mapLog.src_x + 1][mapLog.src_y].pic_y;
					//画上面
					putimage(
						mapArr[mapLog.src_x][mapLog.src_y].pos_x, //空格位置
						mapArr[mapLog.src_x][mapLog.src_y].pos_y,
						99, 99, &sbImg,
						mapArr[mapLog.src_x + 1][mapLog.src_y].pic_x,
						mapArr[mapLog.src_x + 1][mapLog.src_y].pic_y);
					mapArr[mapLog.src_x + 1][mapLog.src_y].notHavePic = true;
					mapArr[mapLog.src_x][mapLog.src_y].notHavePic = false;
					mapLog = FindPosition(mapArr);
				}	
				break;
			case DOWN:
				if (mapLog.src_x != 0)//不是第一行
				{
					//擦除上面
					clearrectangle(
						mapArr[mapLog.src_x - 1][mapLog.src_y].pos_x,
						mapArr[mapLog.src_x - 1][mapLog.src_y].pos_y,
						mapArr[mapLog.src_x - 1][mapLog.src_y].pos_x + 99,
						mapArr[mapLog.src_x - 1][mapLog.src_y].pos_y + 99);
					mapArr[mapLog.src_x][mapLog.src_y].pic_x = mapArr[mapLog.src_x - 1][mapLog.src_y].pic_x;
					mapArr[mapLog.src_x][mapLog.src_y].pic_y = mapArr[mapLog.src_x - 1][mapLog.src_y].pic_y;
					//画下面
					putimage(
						mapArr[mapLog.src_x][mapLog.src_y].pos_x,//空格位置
						mapArr[mapLog.src_x][mapLog.src_y].pos_y,
						99, 99, &sbImg,
						mapArr[mapLog.src_x - 1][mapLog.src_y].pic_x,//画上面的图片
						mapArr[mapLog.src_x - 1][mapLog.src_y].pic_y);
					mapArr[mapLog.src_x - 1][mapLog.src_y].notHavePic = true;
					mapArr[mapLog.src_x][mapLog.src_y].notHavePic = false;
					mapLog = FindPosition(mapArr);
				}
				break;
			case LEFT:
				if (mapLog.src_y != COL-1)//不是第一列
				{
					//擦除右面
					clearrectangle(
						mapArr[mapLog.src_x][mapLog.src_y + 1].pos_x,
						mapArr[mapLog.src_x][mapLog.src_y + 1].pos_y,
						mapArr[mapLog.src_x][mapLog.src_y + 1].pos_x + 99,
						mapArr[mapLog.src_x][mapLog.src_y + 1].pos_y + 99);
					mapArr[mapLog.src_x][mapLog.src_y].pic_x = mapArr[mapLog.src_x][mapLog.src_y + 1].pic_x;
					mapArr[mapLog.src_x][mapLog.src_y].pic_y = mapArr[mapLog.src_x][mapLog.src_y + 1].pic_y;
					//画左面
					putimage(
						mapArr[mapLog.src_x][mapLog.src_y].pos_x,
						mapArr[mapLog.src_x][mapLog.src_y].pos_y,
						99, 99, &sbImg,
						mapArr[mapLog.src_x][mapLog.src_y + 1].pic_x,
						mapArr[mapLog.src_x][mapLog.src_y + 1].pic_y);
					mapArr[mapLog.src_x][mapLog.src_y + 1].notHavePic = true;
					mapArr[mapLog.src_x][mapLog.src_y].notHavePic = false;
				}
				break;
			case RIGHT:
				if (mapLog.src_y != 0)//不是左边
				{
					//擦除左面
					clearrectangle(
						mapArr[mapLog.src_x][mapLog.src_y - 1].pos_x,
						mapArr[mapLog.src_x][mapLog.src_y - 1].pos_y,
						mapArr[mapLog.src_x][mapLog.src_y - 1].pos_x + 99,
						mapArr[mapLog.src_x][mapLog.src_y - 1].pos_y + 99);
					mapArr[mapLog.src_x][mapLog.src_y].pic_x = mapArr[mapLog.src_x][mapLog.src_y - 1].pic_x;
					mapArr[mapLog.src_x][mapLog.src_y].pic_y = mapArr[mapLog.src_x][mapLog.src_y - 1].pic_y;
					//画右面
					putimage(
						mapArr[mapLog.src_x][mapLog.src_y].pos_x,
						mapArr[mapLog.src_x][mapLog.src_y].pos_y,
						99, 99, &sbImg,
						mapArr[mapLog.src_x][mapLog.src_y - 1].pic_x,
						mapArr[mapLog.src_x][mapLog.src_y - 1].pic_y);
					mapArr[mapLog.src_x][mapLog.src_y - 1].notHavePic = true;
					mapArr[mapLog.src_x][mapLog.src_y].notHavePic = false;
				}
				break;
			}
		}
	}
}