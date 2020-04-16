/*================================================================
*   Copyright (C) 2019 * Ltd. All rights reserved.
*   
*   File name   : myTcpServer.c
*   Author      : mabu
*   QQ          : 1105403369
*   Created date: 2019-11-01 16:02:06
*   Description : 
*
*===============================================================*/


#include<sys/socket.h>
#include<sys/types.h>
#include<errno.h>
#include<stdio.h>
#include<arpa/inet.h>
#include<netinet/in.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#define BUFSIZE 1024
#define SERVER_PORT 8800	      //服务器端口
const char clientIp[]="127.0.0.1";//客户端的ip地址

int main(int argc,char *argv[])
{
	//创建socket
	int socketfd;
	//创建结构体
	struct sockaddr_in servAddr,clieAddr;
	//获取结构体大小
	socklen_t servLen=sizeof(struct sockaddr);
	//创建缓冲区，存放消息
	char recvBuf[BUFSIZE];
	//accept接收的描述符
	int acceptfd;

	socketfd=socket(AF_INET,SOCK_STREAM,0);
	if(-1==socketfd)
	{
		fprintf(stderr,"socket:%s",strerror(errno));
		exit(1);
	}
	servAddr.sin_family=AF_INET;
	servAddr.sin_port=htons(SERVER_PORT);
	servAddr.sin_addr.s_addr=inet_addr(clientIp);
	//绑定socket
	if(-1==bind(socketfd,(struct sockaddr*)&servAddr,servLen))
	{	
		fprintf(stderr,"bind:%s",strerror(errno));
		exit(1);
	}
	//监听socket
	if(-1==listen(socketfd,10))
	{
		fprintf(stderr,"listen:%s",strerror(errno));
		exit(1);
	}
	while(1)
	{
		//接收
		acceptfd=accept(socketfd,(struct sockaddr*)&clieAddr,&servLen);
		printf("socke描述符：%d",acceptfd);
		while(1)
		{
			//开始接收消息
			if(-1==recv(acceptfd,recvBuf,BUFSIZE,0))
			{
				fprintf(stderr ,"recv:%s",strerror(errno));
				exit(1);
			}
			printf("%s",recvBuf);
		}
	}
	close(socketfd);
	return 0;
}
