#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<windows.h> 
#include<conio.h> 
#include "diynode.h"
#include "Subtask1.h"
#include "Subtask2.h" 
#include "Subtask3.h"
#include "Subtask4.h"
#include "Subtask5.h"
#include "Subtask6.h"
#include "RSA.h"
#define GameCnt 8
const long long mask = 3986329060925346962LL; //����������� 
node Data[55]; //��Ϸ���� 
static char wr[1000005];
int id; //nΪ�û�����, idΪ��ǰ�û���Ӧ���������, ����Data[]�±�, taskid��ʾ��ǰ���ڽ��л򼴽�����Ĺؿ� 
static int n, taskid; 
static FILE *io;
static char graphtext[10][1005] = {
	"|  ______              _         ______                      _                 _____                                    |\n",
	"|  | ___ \\            (_)        | ___ \\                    (_)               |  __ \\                                   |\n",
	"|  | |_/ / _ __  __ _  _  _ __   | |_/ / _   _  _ __  _ __   _  _ __    __ _  | |  \\/  __ _  _ __ ___    ___  ___       |\n",
	"|  | ___ \\| '__|/ _` || || '_ \\  | ___ \\| | | || '__|| '_ \\ | || '_ \\  / _` | | | __  / _` || '_ ` _ \\  / _ \\/ __|      |\n",
	"|  | |_/ /| |  | (_| || || | | | | |_/ /| |_| || |   | | | || || | | || (_| | | |_\\ \\| (_| || | | | | ||  __/\\__ \\      |\n",
	"|  \\____/ |_|   \\__,_||_||_| |_| \\____/  \\__,_||_|   |_| |_||_||_| |_| \\__, |  \\____/ \\__,_||_| |_| |_| \\___||___/      |\n",
    "|                                                                       __/ |                                           |\n",
    "|                                                                      |___/                                            |\n",
};

int Max(int a, int b){return a > b ? a : b;}
int Min(int a, int b){return a < b ? a : b;}


static int findid(const char *s){
    for(int i = 1; i <= n; ++i)
        if(strcmp(Data[i].username, s) == 0) return i;
    return -1; 
}

void Switchtask(){ //�л��ؿ� 
    while(1){
    	system("cls");
    	printf("���Ѵ�ͨǰ%d���ؿ�, �����ѡ���1������%d�ص�����ؿ�\n", Data[id].taskid, min(GameCnt, Data[id].taskid+1));
    	printf("�������ѡ��"); taskid = -1;
    	fflush(stdin); scanf("%d", &taskid);
    	if(taskid < 1 || taskid > Data[id].taskid + 1){
			puts("���Ϸ����룡����"); system("pause");
		}
		else 
			break;
	}
}

static void WriteData(){ //���棬д������ 
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
    	long long x = Encode(wr[i] ^ 170);
    	fprintf(io, "%lld ", x); 
	}
    fclose(io);
}

static void ReadData(){
	io = fopen("./data.txt", "r");
    if(io == NULL){
        //puts("Unexpected Error ??? \n(If first run, please try again!)");
        io = fopen("./data.txt", "w"); fclose(io);
        io = fopen("./data.txt", "r");
        if(io == NULL){
        	puts("Unexpected Error ??? \n(If first run, please try again!)");
        	exit(0);
		}
    }
	int rd_n = 0;long long x; fscanf(io, "%d", &rd_n);
	for(int i = 0; i < rd_n; ++i){
		fscanf(io, "%lld", &x);
		x = Decode(x);
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

static int ReadPassword(char *a, int op){
	if(op == 0) printf("Password:");
	else printf("Password[again]:");
	int i = 0; memset(a, 0, sizeof a);
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
		if(c == ' '){
			printf("\n��������Ƿ��ַ�\n");
			putchar('\n'); return 0; 
		}
		if(i == 30){
			printf("\nPassword is too long, please try again!\n");
			putchar('\n'); return 0;
		}
		a[i++] = c;
		printf("*");
	}
	putchar('\n'); 
	return 1;
}

static void Register(){
	if(n >= 50){
		puts("�û������Ѵ�����������ϵ����Ա�������ݣ�");
		system("pause"); return; 
	}
    ++n; char s[34];
    while(1){
    	printf("Username: "); memset(Data[n].username, 0, sizeof Data[n].username); 
    	fflush(stdin); scanf("%10s", Data[n].username); fflush(stdin);
    	int flag = 0;
    	for(int i = 1; i <= n - 1; ++i)
    		if(strcmp(Data[n].username, Data[i].username) == 0){
    			printf("This username has been existed!\n");
				flag = 1; break; 
			} 
		if(flag) continue;
    	while(ReadPassword(Data[n].password, 0) == 0);
    	while(ReadPassword(s, 1) == 0);
		if(strcmp(Data[n].password, s)){
			puts("�����������벻һ�£������ԣ�");
			continue; 
		}
		Data[n].taskid = 0;
    	printf("ע��ɹ������UsernameΪ %s ���μǣ�\n", Data[n].username); Sleep(2500); 
    	break;
	}
}   

static int Login(){
    if(n == 0){
        puts("No data availible!");
        system("pause"); return 0;
    }
    printf("Username:");
    char username[10];
    fflush(stdin); scanf("%10s", username); 
    id = findid(username);
    if(id == -1){
        puts("This username is not existed.");
        system("pause"); return 0;
    }
    //printf("Password:"); 
	char st[35];
    //scanf("%lld", &x);
    //if(x == (Data[id].password ^ mask)){
    for(int i = 1; i <= 3; ++i){
    	memset(st, 0, sizeof(st)); ReadPassword(st, 0);
    	if(strcmp(st, Data[id].password) == 0){
	        puts("��¼�ɹ���"); Sleep(1500);
	        return 1;
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
	WriteData(); system("pause"); exit(0);
}

static void print_logo(){
	printf("�q=====================================================�����==========================================================�r\n");
	printf("|                                          �� �ӭ����������Ϸ���ա� ��                                               |\n");
	for(int i = 0; i < 8; ++i)
		for(int j = 0; j < strlen(graphtext[i]); ++j) 
			putchar(graphtext[i][j]);
	printf("�t=====================================================�����==========================================================�s\n");
    
}

static void SetColor(int color){
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
}

static inline int calc(int i, int op){
	if(op == 0){
		int ret = 0;
		for(int j = 1; j <= GameCnt; ++j) ret += Data[i].data[j][1];
		return ret;
	}
	else return Data[i].data[op][1];
}

static void quicksort(int l,int r, int op)//Ӧ�ö���˼��
{
    int mid = (l + r) >> 1;//�м���
    int i = l, j = r;
    do{
        while(calc(i, op) > calc(mid, op)) i++;//������벿�ֱ��м��������
        while(calc(j, op) < calc(mid, op)) j--;//�����Ұ벿�ֱ��м���С����
        if(i <= j){
        	if(id == i) id = j;
        	else if(id == j) id = i;
            node tmp = Data[i]; Data[i] = Data[j]; Data[j] = tmp;//����
            i++; j--;
        }
    }while(i <= j);//����ע��Ҫ��=
    if(l < j) quicksort(l, j, op);//�ݹ�������벿��
    if(i < r) quicksort(i, r, op);//�ݹ������Ұ벿��
}

void ShowRank(int j){
	quicksort(1, n, j); 
	for(int i = 1; i <= n; ++i)
		printf("\t\t\t\t   %10s   %4d   %4d   %7d   %7d   %7d   \n", Data[i].username, i, Data[i].data[j][1], Data[i].data[j][3], Data[i].data[j][4], Data[i].data[j][5]); 
}

static MainMenu(){
	int op;
    while(1){
		system("cls");
		SetColor(0x0b);
	    print_logo();
	    SetColor(0x0e);
	    puts("Welcome!");
	    puts("��������3��ѡ��");
	    puts("1.��¼�����˺�");
	    puts("2.ע��һ�����û�");
	    puts("3.�˳���Ϸ"); 
	    printf("���������ѡ��");
	    op = -1; fflush(stdin); scanf("%d", &op); fflush(stdin);
	    if(op < 1 || op  > 3) {puts("���Ϸ�����������"); system("pause"); }
		else if(op == 1 && Login(io)) break;
	    else if(op == 2){Register(io); continue;}
	    else if(op == 3){WriteData(io); exit(0);}
	}
}

int main(){
    //system("chcp 65001 >nul");
    //system("color f0");
    system("title ������Ϸ����");
    system("mode con lines=30 cols=125");
    int op;
    ReadData();
    MainMenu();
    while(1){
    	system("mode con lines=30 cols=125");
    	system("cls"); SetColor(0x0b); print_logo(); SetColor(0x0e);
    	//printf("�q=============�����=======�r\n");
		//printf("��  �� ��ͷ�Է籩����ս�� ��  ��\n");
		//printf("�t=======�����=============�s\n");
    	printf("1.ѡ��ؿ�\n2.��������\n3.�˳���¼\n");
		printf("���������ѡ��:");  op = -1;
		fflush(stdin); scanf("%d", &op); fflush(stdin);
		if(op == 1){
			Switchtask();
			if(taskid == 1) Subtask1();
	        else if(taskid == 2) Subtask2();
	        else if(taskid == 3) Subtask3();
	        else if(taskid == 4) Subtask4(); 
	        else if(taskid == 5) Subtask5(); 
	        else if(taskid == 6) Subtask6(); 
	        else continue;
		} else
		if(op == 2){
			quicksort(1, n, 0); system("cls"); 
			printf("��ǰ�û�: %s\n", Data[id].username); 
			printf("\t\t\t\t     Username  ����  �ܷ�  ������Ϸ  ��ȭ��Ϸ  LRL52�Ĳ���  �Զ���  ������Ϸ  ����˹����\n"); 
			for(int i = 1; i <= n; ++i)
				printf("\t\t\t\t   %10s  %4d  %4d  %8d  %8d  %11d  %6d  %8d  %10d\n", Data[i].username, i, calc(i, 0), Data[i].data[1][1], Data[i].data[2][1], Data[i].data[3][1], Data[i].data[4][1], Data[i].data[5][1], Data[i].data[6][1]);
			system("pause");  
		} 
		else if(op == 3) MainMenu(); 
		else { puts("���Ϸ�����������"); system("pause"); }
    }
    //WriteData(io);
    return 0;
}
