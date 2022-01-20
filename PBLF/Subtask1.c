#include "Subtask1.h"
#include "diynode.h"
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
extern node Data[];
extern int n, id, taskid;
#define up 26
int lg[up+5];

void Game(){
	for(int i = 2; i <= up; ++i) lg[i] = lg[i>>1] + 1;
	srand((unsigned)time(NULL));
	int num = rand() % 26 + 1, x, cnt = 0, maxcnt = lg[up]+1;
	while(1){
		if(cnt > maxcnt){
			puts("次数超过限制，你再想想，游戏失败!!!");
			return;
		}
		printf("请输入你的Guess:"); 
		scanf("%d", &x);
		++cnt;
		if(x > num) printf("太大了\n");
		else if(x < num) printf("太小了\n");
		else{
			puts("Congratulations! 你猜对了诶!");
			if(Data[id].data[1][1]) Data[id].data[1][1] = Min(Data[id].data[1][1], cnt);
			else{
				Data[id].data[1][0] = 1;
				Data[id].data[1][1] = cnt;
			}
			Data[id].taskid = Max(Data[id].taskid, 1);
			return;
		} 
	}
}

void Subtask1(){
    puts("欢迎来到猜数小游戏:");
	printf("LRL52随机生成一个1—%d的整数，你输入猜数猜数结果，LRL52会反馈给你猜数结果的相对大小\n", up);
	puts("你有一定的次数限制，次数越少更优"); 
    if(Data[id].data[1][1]) printf("你上次的最佳记录是%d次\n", Data[id].data[1][1]);
	int op;
	while(1){
		printf("1.开始游戏\n2.切换关卡\n3.退出游戏\n");
		puts("请输入你的选择:"); 
		scanf("%d", &op);
		if(op == 1) Game();
		else if(op == 2){
			Switchtask();
			return;
		}else{
			taskid = -1;
			return;
		}
	}
}
