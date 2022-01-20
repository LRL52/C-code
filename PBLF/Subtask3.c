#include "Subtask3.h" //引入你的头文件
#include "diynode.h"  //引入自定义结构体类型,
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<windows.h>
extern node Data[]; //共享游戏数据Data 
extern int id, taskid; //共享id, taskid, id为当前用户对应的数字序号, 用作Data[]下标, taskid表示当前正在进行或即将进入的关卡, 你很可能会用到 
//你可以在下面写函数，定义变量等等
#define n 5
#define m 25
int a[n+5];
typedef struct ListNode{
    int x, y;
    struct ListNode *prev;
}ListNode;
ListNode *head, *tail;

void print(){
    printf("现有的%d堆石子数量依次为：\n", n);
    for(int i = 1; i <= n; ++i) printf("%d ", a[i]);
    putchar('\n'); putchar('\n');
}

int checkend(){
    for(int i = 1; i <= n; ++i) if(a[i] > 0) return 0;
    return 1;
}

void Insert(int x, int y){
    ListNode *cur = (ListNode*)malloc(sizeof(ListNode));
    cur->x = x, cur->y = y;
    cur->prev = tail, tail = cur;
}

void Delete(){
    if(tail == head){
        printf("不合法的操作！！！\n\n");
        return;
    }
    static ListNode *p;
    a[tail->x] += tail->y, p = tail, tail = tail->prev, free(p);
    a[tail->x] += tail->y, p = tail, tail = tail->prev, free(p);
    puts("撤回成功"); Sleep(2000);
    print();
}

void NimGame(){
    printf("\n-------------------初始化游戏---------------------\n");
    Sleep(1000); head = (ListNode*)malloc(sizeof(ListNode)), tail = head;
    printf("请每次输入用空格分隔的2个数x y\n表示将第x堆石子拿走y个\n输入-1表示撤回上一次你和LRL52的操作\n\n");
    srand((unsigned)time(NULL)); int x = 0, y = 0;
    for(int i = 1; i <= n - 1; ++i) a[i] = rand() * rand() % m + 1, x ^= a[i];
    if(x > 0 && rand() % 5) a[n] = x;
    else a[n] = rand() * rand() % m + 1;
    while(1){
        print();
        if(checkend()){
            puts("You loss the game! ! !");
            return;
        }
        while(1){
            printf("请输入你的操作x y:");
            scanf("%d", &x);
            if(x == -1){
                Delete(); fflush(stdin);
                continue;
            }
            scanf("%d", &y); fflush(stdin);
            if(x > n || x < 1 || y <= 0 || a[x] < y){
                puts("不合法的操作！！！");
                continue;
            }
            a[x] -= y;
            Insert(x, y);
            break;
        }
        print();
        if(checkend()){
            puts("Congratulations, You win!");
            return;
        }
        Sleep(2000); x = 0;
        for(int i = 1; i <= n; ++i) x ^= a[i];
        if(x){
            for(int i = 1; i <= n; ++i)
                if((a[i] ^ x) < a[i]){
                    y = a[i] - (a[i]^x);
                    printf("LRL52决定将第%d堆石子拿走%d颗\n", i, y);
                    a[i] -= y; Insert(i, y);
                    break;
                }
        } else{
            for(int i = 1; i <= n; ++i)
                if(a[i] > 0){
                    y = rand() * rand() % a[i] + 1;
                    printf("LRL52决定将第%d堆石子拿走%d颗\n", i, y);
                    a[i] -= y; Insert(i, y);
                    break;
                }
        }
    }
}

void Subtask3(){ //下面将是你的游戏入口, 确保return后将taskid更改为合适的值, 1~Gamecnt表示对应关卡, -1表示退出游戏
    system("cls"); Sleep(1000);
    printf("╭===================○●○●==================╮\n");
	printf("│  ★ ☆欢迎来到Subtask3: LRL52的博弈☆ ★    │\n");
	printf("╰=======○●○●==============================╯\n");
    printf("游戏规则：你有%d堆石子，每一堆石子的个数不超过%d个\n", n, m);
    printf("你和LRL52每次可从任意一堆石子里取出任意多枚石子扔掉，可以取完，不能不取\n");
    printf("每次只能从一堆里取。最后没石子可取的一方就输了\n");
    int op;
	while(1){
		printf("1.开始游戏\n2.切换关卡\n3.退出游戏\n");
		printf("请输入你的选择:"); 
		scanf("%d", &op);
		if(op == 1) NimGame();
		else if(op == 2){
			Switchtask();
			return;
		}else{
			taskid = -1;
			return;
		}
	}
	Switchtask(); //切换关卡, 可在退出时调用
}
