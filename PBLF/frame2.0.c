#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h> 
#include "diynode.h"
#include "Subtask1.h"
#include "Subtask2.h"
#include "Subtask3.h"
#define GameCnt 5
const long long mask = 3986329060925346962LL; //����������� 
node Data[15]; //��Ϸ���� 
char wr[1000005];
int n, id, taskid; //nΪ�û�����, idΪ��ǰ�û���Ӧ���������, ����Data[]�±�, taskid��ʾ��ǰ���ڽ��л򼴽�����Ĺؿ� 
int Max(int a, int b){return a > b ? a : b;}
int Min(int a, int b){return a < b ? a : b;}

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
    io = fopen("./data.txt", "w");
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
				*a /= 10, --i;
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
	Data[id].taskid = 0;
    taskid = 1;
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
	char st[35]; memset(st, 0, sizeof(st)); ReadPassword(st);
    //scanf("%lld", &x);
    //if(x == (Data[id].password ^ mask)){
    if(strcmp(st, Data[id].password) == 0){
        puts("��¼�ɹ���");
        Switchtask();
    } else{
        puts("Wrong Password!!!");
        WriteData(io); system("pause"); exit(0);
    }
}

void ReadData(FILE *io){
	int rd_n, x; fscanf(io, "%d", &rd_n);
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

int main(){
    //system("chcp 65001 >nul");
    system("cls");
    FILE *io = fopen("./data.txt", "r");
    if(io == NULL){
        puts("Unexpected Error ??? \n(If first run, please try again!)");
        fopen("./data.txt", "w");
        return 0;
    }
    int op;
    ReadData(io);
    puts("Welcome!");
    printf("�q===================�����=======�r\n");
	printf("��  �� �ӭ����������Ϸ���ա� ��  ��\n");
	printf("�t=======�����===================�s\n");
    puts("��������2��ѡ��");
    puts("1.��¼�����˺�");
    puts("2.ע��һ�����û�");
    printf("���������ѡ��");
    scanf("%d", &op);
    if(op == 1) Login(io);
    else if(op == 2) Register(io);
    while(1){
        if(taskid == 1) Subtask1();
        else if(taskid == 2) Subtask2();
        else if(taskid == 3) Subtask3();
        else break;
    }
    WriteData(io);
    return 0;
}
