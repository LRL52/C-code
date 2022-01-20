#include "Subtask3.h" //引入你的头文件
#include "diynode.h"  //引入自定义结构体类型,
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<windows.h>
extern node Data[]; //共享游戏数据Data 
extern int id, taskid; //共享id, taskid, id为当前用户对应的数字序号, 用作Data[]下标, taskid表示当前正在进行或即将进入的关卡, 你很可能会用到 
//你可以在下面写函数，定义变量等等
#define MaxPoints Data[id].data[3][1]
#define Level Data[id].data[3][2]
static int a[100+5];
static int N[] = {0, 3, 5, 7};
static int M[] = {0, 3, 25, 125};
static int pts[] = {0, 1000, 2500, 6666};
typedef struct ListNode{
    int x, y;
    struct ListNode *prev;
}ListNode;
static ListNode *head, *tail;

static void print(int n){
    printf("现有的%d堆石子数量依次为：\n", n);
    for(int i = 1; i <= n; ++i) printf("%d ", a[i]);
    putchar('\n'); putchar('\n');
}

static int checkend(int n){
    for(int i = 1; i <= n; ++i) if(a[i] > 0) return 0;
    return 1;
}

static void Insert(int x, int y){
    ListNode *cur = (ListNode*)malloc(sizeof(ListNode));
    cur->x = x, cur->y = y;
    cur->prev = tail, tail = cur;
}

static void Delete(){
    if(tail == head){
        printf("不合法的操作！！！\n\n");
        return;
    }
    static ListNode *p;
    a[tail->x] += tail->y, p = tail, tail = tail->prev, free(p);
    a[tail->x] += tail->y, p = tail, tail = tail->prev, free(p);
    puts("撤回成功"); Sleep(2000);
}

static void NimGame(int k){
    printf("\n-------------------初始化游戏---------------------\n"); 
    Sleep(1000); head = (ListNode*)malloc(sizeof(ListNode)), tail = head;
    if(k <= 2) printf("当前为第 %d 个子关卡: 共有 %d 堆石子，每堆石子的个数不超过 %d 个\n", k, N[k], M[k]); 
	else printf("当前为第 %d 个(BOSS)子关卡: 共有 %d 堆石子，每堆石子的个数不超过 %d 个，且你仅有3次撤回机会\n", k, N[k], M[k]);
	printf("请每次输入用空格分隔的2个数x y\n表示将第x堆石子拿走y个\n输入-1表示撤回上一次你和LRL52的操作，输入-2表示退出本局游戏\n\n");
    srand((unsigned)time(NULL)); int x = 0, y = 0, n = N[k], m = M[k], cnt = 0;
    for(int i = 1; i <= n - 1; ++i) a[i] = rand() * rand() % m + 1, x ^= a[i];
    if(k == 1){
    	for(int i = 1; i <= m; ++i) if(x ^ i) {x ^= i; break;}
    	a[n] = x;
	} else{
		if(x > 0 && rand() % 5) a[n] = x;
    	else a[n] = rand() * rand() % m + 1;
	}
	clock_t start = clock(), end;
    while(1){
        print(n);
        if(checkend(n)){
            puts("You loss the game! ! !");
            system("pause"); return;
        }
        while(1){
            printf("请输入你的操作x y:");
            fflush(stdin); x = 0; scanf("%d", &x);
            if(x == -1){
            	if(k == 3 && cnt == 3){
            		puts("撤回次数已达上限，操作无效！"); 
            		continue; 
				}
                Delete(); print(n);  fflush(stdin); ++cnt;
                continue;
            }
            if(x == -2){fflush(stdin); return;}
            scanf("%d", &y); fflush(stdin);
            if(x > n || x < 1 || y <= 0 || a[x] < y){
                puts("不合法的操作！！！");
                continue;
            }
            a[x] -= y;
            Insert(x, y);
            break;
        }
        print(n);
        if(checkend(n)){
            puts("Congratulations, You win!");
            end = clock(); double dur=(double)(end-start)/CLK_TCK;
			int this_pts = pts[k] - Min((int)dur * 2, 495) - Min(50 * cnt, 495);
			Data[id].data[3][2+k] = Max(Data[id].data[3][2+k], this_pts);
			printf("当前为第 %d 个子关卡，本次得分 %d  用时：%.3lfs 撤回次数：%d  最高得分 %d\n", k, this_pts, dur, cnt, Data[id].data[3][2+k]);
 			MaxPoints = Max(MaxPoints, Data[id].data[3][3] + Data[id].data[3][4] + Data[id].data[3][5]);
			Level = Max(Level, k);
			Data[id].taskid = Data[id].taskid > 3 ? Data[id].taskid : 3; system("pause");
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
    Data[id].data[3][0] = 5;
    int op = -1; Sleep(1000); 
	while(1){
		system("cls");
		printf("╭===================○●○●==================╮\n");
		printf("│  ★ ☆欢迎来到Subtask3: LRL52的博弈☆ ★    │\n");
		printf("╰=======○●○●==============================╯\n");
	    printf("游戏规则：你有若干堆给定数量的石子\n");
	    printf("你和LRL52每次可从任意一堆石子里取出任意多枚石子扔掉，可以取完，不能不取，你拥有尊贵的先手资格\n");
    	printf("每次只能从一堆里取。最后没石子可取的一方就输了\n");
		printf("1.开始游戏\n2.历史记录\n3.退出游戏\n");
		printf("请输入你的选择:"); 
		fflush(stdin); scanf("%d", &op); fflush(stdin);
		if(op == 1){
			printf("你的最高记录是通过了前 %d 个子关卡，故你可以选择1 - %d中的任意子关卡\n", Level, Min(3, Level+1));
			printf("请输入你的选择:"); op = -1; scanf("%d", &op); fflush(stdin); 
			if(op < 1 || op > Min(3, Level+1)) {puts("不合法操作！！！"); system("pause");}
			else NimGame(op); 
		}
		else if(op == 2){
			system("cls"); printf("当前关卡：LRL52的博弈[关卡2]   当前用户: %s\n\n", Data[id].username);  
			printf("\t\t\t\t     Username   名次   总分   子关卡1   子关卡2   子关卡3  \n");
			ShowRank(3);
			//printf("\t\t\t\t  %22d   %7d   %7d   %7d   \n", MaxPoints, Data[id].data[3][3], Data[id].data[3][4], Data[id].data[3][5]);
			system("pause");
		} 
		else if(op == 3) return;
		else { puts("不合法操作！！！"); system("pause"); } 
	}
}
