#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
static char str[1000005];
char ipAddr[INET_ADDRSTRLEN];//保存点分十进制的地址

int main(){
    //创建套接字
    int serv_sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

    //将套接字和IP、端口绑定
    struct sockaddr_in serv_addr;
    memset(&serv_addr, 0, sizeof(serv_addr));  //每个字节都用0填充
    serv_addr.sin_family = AF_INET;  //使用IPv4地址
    serv_addr.sin_addr.s_addr = inet_addr("10.0.4.3");  //具体的IP地址
    //serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(1024);  //端口
    bind(serv_sock, (struct sockaddr*)&serv_addr, sizeof(serv_addr));

    //进入监听状态，等待用户发起请求
    listen(serv_sock, 20);
    
    //接收客户端请求
    int cnt = 0;
    while(1){
        struct sockaddr_in clnt_addr;
        socklen_t clnt_addr_size = sizeof(clnt_addr);
        int clnt_sock = accept(serv_sock, (struct sockaddr*)&clnt_addr, &clnt_addr_size);

        //向客户端发送数据
       	FILE *log = fopen("./log.txt", "a");
			  fprintf(log, "第 %d 个用户成功连接服务器\n", ++cnt);
				fprintf(log, "Peer Address = %s:%d\n", inet_ntop(AF_INET, &clnt_addr.sin_addr, ipAddr, sizeof(ipAddr)), ntohs(clnt_addr.sin_port));
				fclose(log);
				
        FILE *io = fopen("./data.txt", "r");
        fread(str, 1, sizeof(str), io);
        fclose(io); 
        
				int len = strlen(str); char Len[25] = {0};
				sprintf(Len, "%d", len);
				write(clnt_sock, Len, sizeof(Len));
        write(clnt_sock, str, len);
		
	    	memset(str, 0, sizeof str);
				memset(Len, 0, sizeof Len);
				read(clnt_sock, Len, sizeof Len);
				len = 0; int tot = 0;
				sscanf(Len, "%d", &len);
				if(len <= 0) continue;
				while(1){
						int  ret = read(clnt_sock, str + tot, sizeof(str));
						tot += ret;
						if(tot == len) break;
				}
        //read(clnt_sock, str, sizeof(str));
        if(strlen(str) == 0) continue;
        
        //关闭套接字
        close(clnt_sock);
        log = fopen("./log.txt", "a");
				fprintf(log, "第 %d 个用户已经断开服务器\n", cnt);
				fclose(log);
        
        io = fopen("./data.txt", "w");
        fwrite(str, 1, strlen(str), io);
        fclose(io);
    }
    
    close(serv_sock);

    return 0;
}

