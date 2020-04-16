/*================================================================
*   Copyright (C) 2019 * Ltd. All rights reserved.
*   
*   File name   : myTcpClient.c
*   Author      : mabu
*   QQ          : 1105403369
*   Created date: 2019-11-01 16:36:57
*   Description : 
*
*===============================================================*/


#include<sys/socket.h>
#include<sys/types.h>
#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include<string.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<unistd.h>
#define SEND_BUF 1024
#define SERVER_PORT 8800		//服务器端口
const char servIp[]="127.0.0.1";//服务器ip地址

int main(int argc,char *argv[])
{
	//创建socket
	int socketfd;
	//创建结构体存放数据
	struct sockaddr_in servAddr;
	//存放结构体长度
	socklen_t servLen=sizeof(struct sockaddr);
	//数组保存消息
	char sendBuf[SEND_BUF];

	socketfd=socket(AF_INET,SOCK_STREAM,0);
	if(-1==socketfd)
	{
		fprintf(stderr,"error:%s",strerror(errno));
		exit(1);
	}

	servAddr.sin_family=AF_INET;
	servAddr.sin_port=htons(SERVER_PORT);
	servAddr.sin_addr.s_addr=inet_addr(servIp);
	//连接ip和端口
	if(-1==connect(socketfd,(struct sockaddr*)&servAddr,servLen))
	{
		fprintf(stderr,"error:%s",strerror(errno));
		exit(1);
	}
	while(1)
	{
		fgets(sendBuf,SEND_BUF,stdin);
		if(-1==send(socketfd,sendBuf,SEND_BUF,0))
		{
			fprintf(stderr,"error:%s",strerror(errno));
			exit(1);
		}
	}
	close(socketfd);
	return 0;
}
