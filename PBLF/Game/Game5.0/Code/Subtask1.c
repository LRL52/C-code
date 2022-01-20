#include "Subtask1.h"
#include "diynode.h"
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
extern node Data[];
extern int n, id, taskid;
#define MaxPoints Data[id].data[1][1]
#define Level Data[id].data[1][2]
//#define LastPoints Data[id].data[1][3]
static int lg[666666+5];
static int up[] = {0, 26, 520, 666666};
static int pts[] = {0, 1000, 2500, 6666};

/*int RecvChoose(){
	printf("1.重玩该子关卡（刷分）\n2.继续该游戏的下一个子关卡\n3.返回游戏菜单\n");
	printf("请输入你的选择:");
	scanf("%d", &op); fflush(stdin); return op; 
}*/ 

static void Game(int k){
	srand((unsigned)time(NULL));
	int num = 1LL * rand() * rand() * rand() % up[k] + 1, x, cnt = 0, maxcnt = lg[up[k]]+1;
	clock_t start = clock(), end; //int Points = 0; 
	if(k <= 2) printf("当前为第 %d 个子关卡，生成数的范围是1 - %d，你可以无限制猜数\n", k, up[k]); 
	else printf("当前为第 %d 个(BOSS)子关卡，生成数的范围是1 - %d，你最多只有%d次猜测机会\n", k, up[k], maxcnt); 
	while(1){
		if(cnt > maxcnt && k >= 2){
			puts("次数超过限制，你再想想，游戏失败!!!");
			printf("正确答案是 %d \n", num); 
			system("pause");
			return; 
		}
		printf("请输入你的Guess:"); 
		fflush(stdin); int ret = scanf("%d", &x); fflush(stdin);
		++cnt;
		if(ret == 0) {
			puts("不合法操作！");
			continue; 
		}
		if(x > num) printf("太大了\n");
		else if(x < num) printf("太小了\n");
		else{
			puts("Congratulations! 你猜对了诶!"); end = clock(); double dur=(double)(end-start)/CLK_TCK;
			int this_pts = pts[k] - Min((int)dur * 2, 495) - Min(50 * (cnt-1), 495);
			Data[id].data[1][2+k] = Max(Data[id].data[1][2+k], this_pts);
			printf("当前为第 %d 个子关卡，本次得分 %d  用时：%.3lfs 最高得分 %d\n", k, this_pts, dur, Data[id].data[1][2+k]);
 			MaxPoints = Max(MaxPoints, Data[id].data[1][3] + Data[id].data[1][4] + Data[id].data[1][5]);
			Level = Max(Level, k);
			Data[id].taskid = Data[id].taskid > 1 ? Data[id].taskid : 1; system("pause");
 			return;
		} 
	}
}

/*void Assignwork(int option){
	int entrance = 1;
	(option == 1){
		if(LastLevel > 0){
			pritnf("你上次通过了前 %d 个子关卡，你的目前得分为 %d\n", LastLevel, LastPoints); 
			printf("下面你讲进入第 %d 个子关卡，祝你好运！\n", LastLevel + 1);
			entrance = LastLevel + 1;
		} else
		puts("你还没有过游戏记录或者上次你已AC，下面将为你开启一个新游戏\n"); 
	}
	while(entrance <= 3){
		int op = Game(entrance);
		if(op == 1) {};
		else if(op == 2){
			++entranre;
			LastPoints = 
		}
	}
}*/

void Subtask1(){
	//puts("你有一定的次数限制，次数越少更优"); 
    //if(Data[id].data[1][1]) printf("你上次的最佳记录是%d次\n", Data[id].data[1][1]);
	int op = -1; Data[id].data[1][0] = 5;
	if(lg[2] == 0)
		for(int i = 2; i <= 666666; ++i) lg[i] = lg[i>>1] + 1; 
	while(1){
		system("cls"); 
    	puts("欢迎来到猜数小游戏, 本游戏共有3个子关卡, 通过第1个即可进入下一个游戏:");
		printf("LRL52随机生成一个给定范围的整数，你输入猜数猜数结果，LRL52会反馈给你猜数结果的相对大小\n");
		printf("1.开始游戏\n2.历史记录\n3.退出游戏\n");
		printf("请输入你的选择:");  op = -1;
		fflush(stdin); scanf("%d", &op); fflush(stdin);
		if(op == 1){
			printf("你的最高记录是通过了前 %d 个子关卡，故你可以选择1 - %d中的任意子关卡\n", Level, Min(3, Level+1));
			printf("请输入你的选择:"); op = -1; fflush(stdin); scanf("%d", &op); fflush(stdin); 
			if(op < 1 || op > Min(3, Level+1)){puts("不合法操作！！！"); system("pause");}
			else Game(op); 
		}
		else if(op == 2){
			/*system("cls"); printf("当前用户: %s\n", Data[id].username); 
			printf("\t\t\t\t  猜数游戏[关卡1]总分   子关卡1   子关卡2   子关卡3  \n");
			printf("\t\t\t\t  %18d   %7d   %7d   %7d   \n", MaxPoints, Data[id].data[1][3], Data[id].data[1][4], Data[id].data[1][5]);
			system("pause");*/
			system("cls"); printf("当前关卡：猜数游戏[关卡1]   当前用户: %s\n\n", Data[id].username);  
			printf("\t\t\t\t     Username   名次   总分   子关卡1   子关卡2   子关卡3  \n");
			ShowRank(1);
			system("pause");
		} 
		else if(op == 3) return;
		else {puts("不合法操作！！！"); system("pause");}
	}
}
