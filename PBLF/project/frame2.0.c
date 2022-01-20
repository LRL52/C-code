#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h> 
#include "diynode.h"
#include "Subtask1.h"
#include "Subtask2.h"
#include "Subtask3.h"
#include "Subtask5.h"
#define GameCnt 5
const long long mask = 3986329060925346962LL; //����������� 
node Data[15]; //��Ϸ���� 
char wr[1000005];
int n, id, taskid; //nΪ�û�����, idΪ��ǰ�û���Ӧ���������, ����Data[]�±�, taskid��ʾ��ǰ���ڽ��л򼴽�����Ĺؿ� 
char graphtext[10][1005] = {
	"|  ______              _         ______                      _                 _____                                |\n",
	"|  | ___ \\            (_)        | ___ \\                    (_)               |  __ \\                               |\n",
	"|  | |_/ / _ __  __ _  _  _ __   | |_/ / _   _  _ __  _ __   _  _ __    __ _  | |  \\/  __ _  _ __ ___    ___  ___   |\n",
	"|  | ___ \\| '__|/ _` || || '_ \\  | ___ \\| | | || '__|| '_ \\ | || '_ \\  / _` | | | __  / _` || '_ ` _ \\  / _ \\/ __|  |\n",
	"|  | |_/ /| |  | (_| || || | | | | |_/ /| |_| || |   | | | || || | | || (_| | | |_\\ \\| (_| || | | | | ||  __/\\__ \\  |\n",
	"|  \\____/ |_|   \\__,_||_||_| |_| \\____/  \\__,_||_|   |_| |_||_||_| |_| \\__, |  \\____/ \\__,_||_| |_| |_| \\___||___/  |\n",
    "|                                                                       __/ |                                       |\n",
    "|                                                                      |___/                                        |\n",
};


int findid(const char *s){
    for(int i = 1; i <= n; ++i)
        if(strcmp(Data[i].username, s) == 0) return i;
    return -1; 
}

void Switchtask(){ //�л��ؿ� 
    printf("���Ѵ�ͨǰ%d���ؿ�, �����ѡ���1������%d�ص�����ؿ�\n", Data[id].taskid, min(GameCnt, Data[id].taskid+1));
    printf("�������ѡ��");
    scanf("%d", &taskid);
}

void WriteData(FILE *io){ //���棬д������ 
	memset(wr, 0, sizeof(wr)); char *p = wr;
    p += sprintf(p, "%d\n", n);
    for(int k = 1; k <= n; ++k){
        p += sprintf(p, "%s %s %d\n", Data[k].username, Data[k].password, Data[k].taskid);
        for(int i = 1; i <= GameCnt; ++i){
            p += sprintf(p, "%d", Data[k].data[i][0]);
            for(int j = 1; j <= Data[k].data[i][0]; ++j)
                p += sprintf(p, " %d", Data[k].data[i][j]);
            //fputc('\n', io);
            p += sprintf(p, "\n");
        }
    }
    io = fopen("./data0.txt", "w");
    int len = strlen(wr); fprintf(io, "%d\n", len);
    for(int i = 0; i < len; ++i){
    	fprintf(io, "%d ", wr[i] ^ 170); 
	}
    fclose(io);
}

void ReadPassword(char *a){
	printf("Password:");
	int i = 0; *a = 0;
	while (1) { 
		char c = getch();
		if (c == '\r') { //����س����˳�ѭ��
			break;
		}
		if (c == '\b') { //delete��
			if (i > 0) {
				a[--i] = '\0';
				printf("\b");	//���\b���ù�����һ��
				printf(" \b");  //����ո񸲸ǵ�Ҫɾ�����ַ���Ȼ�����\b�ٰѹ����ˡ�
			}
			continue;
		}
		//*a = (*a) * 10 + (c - '0');
		//++i;
		a[i++] = c;
		printf("*");
	}
	putchar('\n'); 
}

void Register(FILE *io){
    id = ++n;
    printf("Username: ");
    scanf("%s", Data[id].username);
    //printf("Password:");
    //scanf("%lld", &Data[id].password);
    ReadPassword(&Data[id].password);
    //Data[id].password ^= mask, 
	Data[id].taskid = 5;
    taskid = 1;
    puts("ע��ɹ���"); Sleep(1500); 
}   

void Login(FILE *io){
    if(n == 0){
        puts("No data availible!");
        WriteData(io); system("pause");exit(0);
    }
    printf("Username:");
    char username[10];
    scanf("%s", username);
    id = findid(username);
    if(id == -1){
        puts("This username is not existed.");
        WriteData(io); system("pause"); exit(0);
    }
    //printf("Password:"); 
	char st[35];
    //scanf("%lld", &x);
    //if(x == (Data[id].password ^ mask)){
    for(int i = 1; i <= 3; ++i){
    	memset(st, 0, sizeof(st)); ReadPassword(st);
    	if(strcmp(st, Data[id].password) == 0){
	        puts("��¼�ɹ���"); Sleep(1500);
	        return;
	    } else{
	        puts("Wrong Password!!!");
	    }
	}
	for(int i = 3; i >= 1; --i){
		printf("������������3�Σ������� %d ����˳�...", i);
		Sleep(1000); 
		for(int j = 1; j <= 41; ++j) 
			printf("\b \b"); 
	}
	WriteData(io); system("pause"); exit(0);
}

void ReadData(FILE *io){
	int rd_n = 0, x; fscanf(io, "%d", &rd_n);
	for(int i = 0; i < rd_n; ++i){
		fscanf(io, "%d", &x);
		wr[i] = x ^ 170;
	}
	fclose(io);
	FILE *tempio = fopen("./tempdata.txt", "w");
	fputs(wr, tempio);
	fclose(tempio);
	tempio = fopen("./tempdata.txt", "r");
	fscanf(tempio, "%d", &n);
    for(int k = 1; k <= n; ++k){
        fscanf(tempio, "%s%s%d", Data[k].username, Data[k].password, &Data[k].taskid);
        for(int i = 1; i <= GameCnt; ++i){
            fscanf(tempio, "%d", &Data[k].data[i][0]);
            for(int j = 1; j <= Data[k].data[i][0]; ++j) fscanf(tempio, "%d", &Data[k].data[i][j]);
        }
    }
    fclose(tempio);
    remove("./tempdata.txt"); 
}

void print_logo(){
	printf("�q=====================================================�����=====================================================�r\n");
	printf("��                                          �� �ӭ����������Ϸ���ա� ��                                           ��\n");
	for(int i = 0; i < 8; ++i)
		for(int j = 0; j < strlen(graphtext[i]); ++j) 
			putchar(graphtext[i][j]);
	printf("�t=====================================================�����=====================================================�s\n");
    
}

void SetColor(int color){
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
}

int main(){
    //system("chcp 65001 >nul");
    system("cls");
    //system("color f0");
    FILE *io = fopen("./data.txt", "r");
    if(io == NULL){
        //puts("Unexpected Error ??? \n(If first run, please try again!)");
        io = fopen("./data.txt", "w"); fclose(io);
        io = fopen("./data.txt", "r");
        if(io == NULL){
        	puts("Unexpected Error ??? \n(If first run, please try again!)");
        	return 0;
		}
    }
    int op;
    ReadData(io);
    SetColor(0x0b);
    print_logo();
    SetColor(0x0e);
    puts("Welcome!");
    puts("��������2��ѡ��");
    puts("1.��¼�����˺�");
    puts("2.ע��һ�����û�");
    printf("���������ѡ��");
    scanf("%d", &op);
    if(op == 1) Login(io);
    else if(op == 2) Register(io);
    while(1){
    	system("cls"); SetColor(0x0b); print_logo(); SetColor(0x0e);
    	//printf("�q=============�����=======�r\n");
		//printf("��  �� ��ͷ�Է籩����ս�� ��  ��\n");
		//printf("�t=======�����=============�s\n");
    	printf("1.ѡ��ؿ�\n2.�˳���Ϸ\n");
		printf("���������ѡ��:");  op = -1;
		scanf("%d", &op);
		if(op == 1){
			Switchtask();
			if(taskid == 1) Subtask1();
	        else if(taskid == 2) Subtask2();
	        else if(taskid == 3) Subtask3();
	        else if(taskid == 5) Subtask5(); 
	        else continue;
		}
		else break; 
    }
    WriteData(io);
    return 0;
}
