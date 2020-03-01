/******************************
*动态内存实现二维数组.cpp
*******************************/
#include<iostream>     
#include<time.h>     
#include<stdlib.h>     

int	main()
{
	srand((unsigned)time(NULL));

	//申请一个10*10的动态二维数组     
	int	**p = new	int*[10];//申请10个int*型的动态内存     
	for (int i = 0; i < 10; i++)
	{
		p[i] = new	int[10];//每一个int*指针指向一片连续空间有10个int型数字     
	}

	//定义一个数组用来储存数字1~6出现的偶数次     
	int	log, arr[6];
	for (int i = 0; i < 6;)
	{
		log = rand() % 13 + 1;
		if (log % 2 == 0)//c次数范围：1-12次     
		{
			arr[i] = log;
			i += 1;
		}
	}

	//全部赋值为0     
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			p[i][j] = 0;
		}
	}

	int	i, j;
	for (int z = 0; z < 6; z++)//把数字1~6随机打印在二维数组上     
	{
		for (int times = 0; times < 12; times++)//数字出现的次数     
		{
			if (times	<	arr[z])
			{
				i = rand() % 10;
				j = rand() % 10;
				if (p[i][j] != 0)
				{
					times -= 1;
				}
				else
					p[i][j] = z + 1;
			}
			else
				break;
		}
	}

	//以行列式打印内存中的数值     
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			printf("%d", p[i][j]);
		}
		printf("\n");     
	}

	//释放内存     
	for (int i = 0; i < 10; i++)
	{
		delete[]	p[i];
	}
	delete[]	p;
	return	0;
}