/*================================================================
*   Copyright (C) 2019 * Ltd. All rights reserved.
*   
*   File name   : mkfifo.c
*   Author      : mabu
*   QQ          : 1105403369
*   Created date: 2019-11-14 15:30:59
*   Description : mkfifo有名管道（传输速度快呀！）
*
*===============================================================*/


#include<stdio.h>
#include<string.h>
#include<errno.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#define LENGTH 10000

void WriteFile(char *path);
void WriteMkfifo(char *path);
void ReadMkfifo(char *path);
int main(int argc,char *argv[])
{
	//写入一个要传输的文件
	//WriteFile(argv[1]);
	//写一个mkfifo管道
	WriteMkfifo(argv[1]);
	//ReadMkfifo(argv[1]);
	return 0;

}
void ReadMkfifo(char *path)
{
	FILE *readFile;
	char recvBuf[LENGTH*3];
	readFile=fopen(path,"r");
	if(!readFile)
	{
		fprintf(stderr,"read mkfifo error:%s",strerror(errno));
		exit(0);
	}
	while(!feof(readFile))
	{
		fread(recvBuf,10000,1,readFile);
	}
	printf("\n管道mkfifo传输的数据信息：%s\n",recvBuf);

}
void WriteMkfifo(char *path)
{
	const char *mkfifofile="mkfifofile";
	FILE *readFile;
	char buff[LENGTH*3];
	int mkRes;
	if(-1==access(path,F_OK))//文件不存在
	{
		mkRes=mkfifo(mkfifofile,0777);//创建管道
		if(mkRes!=0)//创建管道
		{
			fprintf(stderr,"mkfifo create error:%s",strerror(errno));
			fclose(readFile);
			exit(0);
		}
	}
	//读取txt文件
	readFile=fopen(path,"r");
	if(!readFile)
	{
		fprintf(stderr,"readFile error:%s",strerror(errno));
		exit(0);
	}
	while(!feof(readFile))//如果文件结束返回0,表达式为真
	{
		fgets(buff,100,readFile);
	}
	//把txt文件写入到管道中
	FILE *pfile;
	pfile=fopen(mkfifofile,"w+");
	fwrite(buff,strlen(buff),1,pfile);

	fclose(pfile);
	fclose(readFile);
}
void WriteFile(char *path)
{
	//写入一个要传输的文件
	FILE* writeFile;
	char buff[]="远方啊远方，我看不见你";
	writeFile=fopen(path,"w+");
	if(!writeFile)
	{
		fprintf(stderr,"writeFile error:%s",strerror(errno));
		exit(0);
	}
	for(int i=0;i<LENGTH;++i)
	{
		fputs(buff,writeFile);
	}
	fclose(writeFile);
}
