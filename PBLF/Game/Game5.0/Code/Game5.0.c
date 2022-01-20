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
const long long mask = 3986329060925346962LL; //密码加密掩码 
node Data[55]; //游戏数据 
static char wr[1000005];
int id; //n为用户数量, id为当前用户对应的数字序号, 用作Data[]下标, taskid表示当前正在进行或即将进入的关卡 
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

void Switchtask(){ //切换关卡 
    while(1){
    	system("cls");
    	printf("你已打通前%d个关卡, 你可以选择第1关至第%d关的任意关卡\n", Data[id].taskid, min(GameCnt, Data[id].taskid+1));
    	printf("输入你的选择："); taskid = -1;
    	fflush(stdin); scanf("%d", &taskid);
    	if(taskid < 1 || taskid > Data[id].taskid + 1){
			puts("不合法输入！！！"); system("pause");
		}
		else 
			break;
	}
}

static void WriteData(){ //保存，写入数据 
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
		if (c == '\r') { //输入回车就退出循环
			break;
		}
		if (c == '\b') { //delete键
			if (i > 0) {
				a[--i] = '\0';
				printf("\b");	//输出\b，让光标回退一格
				printf(" \b");  //输出空格覆盖掉要删除的字符，然后输出\b再把光标回退。
			}
			continue;
		}
		//*a = (*a) * 10 + (c - '0');
		//++i;
		if(c == ' '){
			printf("\n请勿输入非法字符\n");
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
		puts("用户数量已达上限吗，请联系管理员处理数据！");
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
			puts("两次输入密码不一致，请重试！");
			continue; 
		}
		Data[n].taskid = 0;
    	printf("注册成功，你的Username为 %s 请牢记！\n", Data[n].username); Sleep(2500); 
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
	        puts("登录成功！"); Sleep(1500);
	        return 1;
	    } else{
	        puts("Wrong Password!!!");
	    }
	}
	for(int i = 3; i >= 1; --i){
		printf("输入密码错误达3次，程序将在 %d 秒后退出...", i);
		Sleep(1000); 
		for(int j = 1; j <= 41; ++j) 
			printf("\b \b"); 
	}
	WriteData(); system("pause"); exit(0);
}

static void print_logo(){
	printf("╭=====================================================○●○●==========================================================╮\n");
	printf("|                                          ★ ☆欢迎来玩烧脑游戏串烧☆ ★                                               |\n");
	for(int i = 0; i < 8; ++i)
		for(int j = 0; j < strlen(graphtext[i]); ++j) 
			putchar(graphtext[i][j]);
	printf("╰=====================================================○●○●==========================================================╯\n");
    
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

static void quicksort(int l,int r, int op)//应用二分思想
{
    int mid = (l + r) >> 1;//中间数
    int i = l, j = r;
    do{
        while(calc(i, op) > calc(mid, op)) i++;//查找左半部分比中间数大的数
        while(calc(j, op) < calc(mid, op)) j--;//查找右半部分比中间数小的数
        if(i <= j){
        	if(id == i) id = j;
        	else if(id == j) id = i;
            node tmp = Data[i]; Data[i] = Data[j]; Data[j] = tmp;//交换
            i++; j--;
        }
    }while(i <= j);//这里注意要有=
    if(l < j) quicksort(l, j, op);//递归搜索左半部分
    if(i < r) quicksort(i, r, op);//递归搜索右半部分
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
	    puts("你有以下3个选择：");
	    puts("1.登录已有账号");
	    puts("2.注册一个新用户");
	    puts("3.退出游戏"); 
	    printf("请输入你的选择：");
	    op = -1; fflush(stdin); scanf("%d", &op); fflush(stdin);
	    if(op < 1 || op  > 3) {puts("不合法操作！！！"); system("pause"); }
		else if(op == 1 && Login(io)) break;
	    else if(op == 2){Register(io); continue;}
	    else if(op == 3){WriteData(io); exit(0);}
	}
}

int main(){
    //system("chcp 65001 >nul");
    //system("color f0");
    system("title 烧脑游戏串烧");
    system("mode con lines=30 cols=125");
    int op;
    ReadData();
    MainMenu();
    while(1){
    	system("mode con lines=30 cols=125");
    	system("cls"); SetColor(0x0b); print_logo(); SetColor(0x0e);
    	//printf("╭=============○●○●=======╮\n");
		//printf("│  ★ ☆头脑风暴大作战☆ ★  │\n");
		//printf("╰=======○●○●=============╯\n");
    	printf("1.选择关卡\n2.天梯排行\n3.退出登录\n");
		printf("请输入你的选择:");  op = -1;
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
			printf("当前用户: %s\n", Data[id].username); 
			printf("\t\t\t\t     Username  名次  总分  猜数游戏  猜拳游戏  LRL52的博弈  吃豆人  长城游戏  俄罗斯方块\n"); 
			for(int i = 1; i <= n; ++i)
				printf("\t\t\t\t   %10s  %4d  %4d  %8d  %8d  %11d  %6d  %8d  %10d\n", Data[i].username, i, calc(i, 0), Data[i].data[1][1], Data[i].data[2][1], Data[i].data[3][1], Data[i].data[4][1], Data[i].data[5][1], Data[i].data[6][1]);
			system("pause");  
		} 
		else if(op == 3) MainMenu(); 
		else { puts("不合法操作！！！"); system("pause"); }
    }
    //WriteData(io);
    return 0;
}
