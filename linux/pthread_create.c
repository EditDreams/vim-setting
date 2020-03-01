/*================================================================
*   Copyright (C) 2019 * Ltd. All rights reserved.
*   
*   File name   : pthread_create.c
*   Author      : mabu
*   QQ          : 1105403369
*   Created date: 2019-11-2 15:50:04
*   Description : 线程的简单创建、join和detach的区别
*
*===============================================================*/


#include<stdio.h>
#include<pthread.h>
#include<unistd.h>

void Run()
{
	int i=0;
	while(1){
		i+=1;
		printf("Run,%d\n",i);
		sleep(1);
	}
}
void Sleep()
{
	int i=0;
	while(1){
		i+=1;
		printf("Sleep,%d\n",i);
		sleep(1);
	}
}

int main(int argc,char*argv[])
{
	pthread_t run_id;
	pthread_t sleep_id;
	
	if(pthread_create(&run_id,NULL,(void *)Run,NULL)!=0)
	{
		printf("create failed!\n");
	}
	//非阻塞自动回收资源
	pthread_detach(run_id);
	if(pthread_create(&sleep_id,NULL,(void *)Sleep,NULL)!=0)
	{
		printf("create pthread failed!\n");
	}
	//阻塞在子线程，回收线程资源
	pthread_join(sleep_id,NULL);
	
	return 0;
}
