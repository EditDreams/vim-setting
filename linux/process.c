/*================================================================
*   Copyright (C) 2019 * Ltd. All rights reserved.
*   
*   File name   : process.c
*   Author      : mabu
*   QQ          : 1105403369
*   Created date: 2019-11-08 19:59:48
*   Description : pipe无名管道 
*
*===============================================================*/


#include<stdio.h>
#include<unistd.h>
#include<errno.h>
#include<string.h>
#include<stdlib.h>
#define SIZE 64

void WriteString(int pipes[]);
void ReadString(int popes[]);

int main(int argc,char* argv[])
{
	pid_t pid;//创建进程id
	int pipes[2],pip;

	pip=pipe(pipes);
	if(-1==pip)
	{
		fprintf(stderr,"error:%s",strerror(errno));
		exit(1);
	}

	pid=fork();//child_id 0 -1
	switch(pid)
	{
		case -1:
			fprintf(stderr,"error:%s",strerror(errno));
			exit(1);
			break;
		case 0://child
			printf("child pid is %d\n",getpid());  //get child id
			printf("child ppid is %d\n",getppid());//get father id
			ReadString(pipes);
			break;
		default://father
			printf("father pid is %d\n",getpid());
			printf("father ppid is %d\n",getppid());
			WriteString(pipes);
			break;
	}
	return 0;
}

void WriteString(int pipes[])
{
	char writeBuf[SIZE]="hello";
	//关闭读管道pipes[0]
	close(pipes[0]);
	
	if(-1==write(pipes[1],writeBuf,strlen(writeBuf)+1))
	{
		fprintf(stderr,"write error:%s",strerror(errno));
		close(pipes[1]);
		exit(1);
	}
	close(pipes[1]);
	exit(0);
}
void ReadString(int pipes[])
{
	char readBuf[SIZE];
	close(pipes[1]);
	if(read(pipes[0],readBuf,SIZE)<0)
	{	
		fprintf(stderr,"read error:%s",strerror(errno));
		close(pipes[0]);
		exit(1);
	}
	printf("%s\n",readBuf);
	close(pipes[0]);
	exit(0);
}
