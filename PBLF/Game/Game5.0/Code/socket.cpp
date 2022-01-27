#include <stdio.h>
#include <stdlib.h>
#include <WinSock2.h>
#include <string.h>
#pragma comment(lib, "ws2_32.lib")  //加载 ws2_32.dll

WSADATA wsaData;
SOCKET sock;
sockaddr_in sockAddr;

int init_socket(){
	//初始化DLL
    WSAStartup(MAKEWORD(2, 2), &wsaData);

    //创建套接字
    sock = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);

    //向服务器发起请求
    memset(&sockAddr, 0, sizeof(sockAddr));  //每个字节都用0填充
    sockAddr.sin_family = PF_INET;
    sockAddr.sin_addr.s_addr = inet_addr("43.132.178.80");
    sockAddr.sin_port = htons(1024);
    return connect(sock, (SOCKADDR*)&sockAddr, sizeof(SOCKADDR));
}

void senddata(char *str){
	int len = strlen(str);
	char Len[25] = {0};
	sprintf(Len, "%d", len);
	send(sock, Len, sizeof(Len), NULL); 
	send(sock, str, strlen(str), NULL);
}

void recvdata(char *str){
	printf("当前已有用户建立连接，请稍等...\n"); 
	char Len[25] = {0};
	recv(sock, Len, sizeof(Len), NULL);
	int len = 0, tot = 0;
	sscanf(Len, "%d", &len);
	if(len <= 0){
		printf("Error: invalid Len!\n");
		exit(0); 
	}
	while(1){
		int ret = recv(sock, str + tot, 1000005, NULL);
		tot += ret;
		//printf("ret = %d tot = %d\n", ret, tot); 
		if(tot == len) return;
	}
}


