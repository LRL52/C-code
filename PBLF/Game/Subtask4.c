#include "Subtask4.h" //引入你的头文件
#include "diynode.h"  //引入自定义结构体类型,
#include<stdio.h>
#include<time.h>
#include<windows.h>
#include<conio.h>
#define enemy 5;
#define stone_hard 1
#define air 0
#define player 3
#define point 2
#define ROW 20
#define COL 20
#define plus 4
extern node Data[]; //共享游戏数据Data 
extern int id, taskid; //共享id, taskid, id为当前用户对应的数字序号, 用作Data[]下标, taskid表示当前正在进行或即将进入的关卡, 你很可能会用到 
//你可以在下面写函数，定义变量等等

//此处可修改敌人数和分数
static int a[20][20] = {
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	{1,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,1,1,0,0,0,0,0,1,1,0,0,0,0,0,0,1},
	{1,0,0,0,1,1,0,0,0,0,1,1,1,0,0,1,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0,1},
	{1,0,0,0,0,0,1,0,0,0,0,0,0,0,1,1,0,0,0,1},
	{1,1,1,0,0,0,1,1,0,0,0,0,0,0,1,1,0,0,0,1},
	{1,1,1,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,1},
	{1,0,0,0,0,1,0,0,0,0,1,0,1,0,0,1,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,1,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,1,1,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,1,1,0,0,1,1,0,0,0,1,0,0,0,0,1,1,0,0,1},
	{1,0,0,0,0,1,1,1,1,1,1,0,0,0,1,1,1,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,1},
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
};
//此处修改地图地形
const static int dx[5] = { 0,1,-1,0,0 };
const static int dy[5] = { 0,0,0,1,-1 };

static void color(int a)//颜色函数
{
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),a);
}
static void gotoxy(int x, int y) {//位置函数(行为x 列为y)
	COORD pos;
	pos.X=2*y;
	pos.Y=x;
	SetConsoleCursorPosition (GetStdHandle (STD_OUTPUT_HANDLE),pos);
}

#define score Data[id].data[4][3]
#define MaxPoints Data[id].data[4][1]
void Subtask4(){ //下面将是你的游戏入口, 确保return后将taskid更改为合适的值, 1~Gamecnt表示对应关卡, -1表示退出游戏
    if(score > 1000) Data[id].taskid = Data[id].taskid > 4 ? Data[id].taskid : 4;
	Data[id].data[4][0] = 5;
	//printf("%d %d\n", Data[id].data[4][4], Data[id].data[4][5]);
	clock_t start,end;
	int choose;
	int point_[20][20];
	memset(point_, 0, sizeof point_);

	int level;
	printf("1.选择难度\n2.查看历史记录\n");
	scanf("%d",&choose);
	if(choose!=1&&choose!=2)
	return; 
	if(choose==1)
	{
	do{
	printf("请输入游戏难度：");
	scanf("%d", &level);
	}while(level==0);
	MessageBox (NULL, "欢迎来到吃豆人游戏！", "温馨提示", MB_OK);
	system("cls");
	for(int i=0;i<20;i++)
	{
		gotoxy(i,22);
		printf("|");
	}
	
	gotoxy(3,23);
	printf("分数: ");
	gotoxy(5,23);
	printf("速度: ");
	gotoxy(7,23);
	printf("时间: ");
	int number_enemy = 10 * level;
	int score_max = 10 * level;
	int speed = 250;

	
	int enemy_x[number_enemy], enemy_y[number_enemy], player_x = 1, player_y = 1, point_x, point_y, before[number_enemy];
	score = score_max;
	memset(before, 0, sizeof before);
	srand((unsigned)time(NULL));
	for (int i = 0; i < score_max; i++)
	{
		point_x = rand() % 18 + 1;
		point_y = rand() % 18 + 1;
		if (a[point_x][point_y] == point)
		{
			i--;
			continue;
		}
		a[point_x][point_y] = point;
		point_[point_x][point_y] = point;
	}
	for (int i = 0; i < number_enemy; i++)
	{
		do {
			enemy_x[i] = rand() % 18 + 1;
			enemy_y[i] = rand() % 18 + 1;//敌人起始位置随机
		} while (a[enemy_x[i]][enemy_y[i]] != 0);
		a[enemy_x[i]][enemy_y[i]] = enemy;
	}

		int speed_x,speed_y;
				do {
			speed_x = rand() % 18 + 1;
			speed_y = rand() % 18 + 1;//敌人起始位置随机
		} while (a[speed_x][speed_y] != 0);
		a[speed_x][speed_y]=plus;
		
			for (int i = 0; i < 20; i++)
		{
			for (int j = 0; j < 20; j++)
			{
				switch (a[i][j])
				{
				case stone_hard:
					color(1);
					gotoxy(i,j);
					printf("■");
					break;

				case point:
					color(3);
					gotoxy(i,j);
					printf("o ");
					break;

				case air:
					gotoxy(i,j);
					printf("  ");
					break;
				case plus:
					color(4);
					gotoxy(i,j);
					printf("+ ");
					break;
				 
				}
			}
			printf("\n");
		}

		int key=1;
		start = clock();
	while (1)
	{
		Sleep(speed);
		if (_kbhit()) {
			switch (_getch())
			{
			case 'd':key = 3;
				break;
			case 's':key = 1;
				break;
			case 'a':key = 4;
				break;
			case 'w':key = 2;
				break;
			}
		
		}//键盘改变移动方向
		if (a[player_x + dx[key]][player_y + dy[key]] != 1)
			{
				if(a[player_x][player_y] == plus)
				{
				speed-=100;
				}
				a[player_x][player_y] = 0;
				point_[player_x][player_y] = 0;
				gotoxy(player_x,player_y);
				printf("  ");
				player_x += dx[key];
				player_y += dy[key];
				gotoxy(player_x,player_y); 
				color(2);
				printf("@");
				
			}
		for (int j = 0; j < 4; j++)
		{
			for (int i = 0; i < 4; i++)
			{
				srand((unsigned)time(NULL));
				for (int i = 0; i < number_enemy; i++)
				{
					int d = rand() % 4 + 1;
					
					if (a[enemy_x[i] + dx[d]][enemy_y[i] + dy[d]] != 1 && a[enemy_x[i] + dx[d]][enemy_y[i] + dy[d]] != 5)
					{
						a[enemy_x[i]][enemy_y[i]] = before[i];
						gotoxy(enemy_x[i],enemy_y[i]);
						if(before[i]==air)
						{
							printf("  ");
						}
						else if(before[i]==point){
							color(3);
							printf("o ");
						}
						else{
							color(4);
							printf("+ ");
						}
						enemy_x[i] += dx[d];
						enemy_y[i] += dy[d];
						before[i] = a[enemy_x[i]][enemy_y[i]];
						gotoxy(enemy_x[i],enemy_y[i]);
						color(4);
						printf("▲");
						
					}

				}goto outloop;
			}
		}outloop:;//敌人随机移动
		for (int i = 0; i < number_enemy; i++)
		{
			if (enemy_x[i] == player_x && enemy_y[i] == player_y)
			{
				color(4);
				MessageBox (NULL, "你输了！！", "温馨提示", MB_OK);
				goto lose;
			}

		}//判断是否输掉游戏
				for(int i=0;i < COL;i++)
		{
			for(int j=0;j < ROW;j++)
			{
				if (point_[i][j] == point)
					score--;
			}
		}
		gotoxy(3,28);
		printf("%d",score);
		gotoxy(5,28);
		printf("%d",100-speed/10);
		end=clock();
		gotoxy(7,28);
		printf("%d",(int)end-start/CLK_TCK);
		if(score==score_max)
		{
		MessageBox (NULL, "你赢了！！", "温馨提示", MB_OK);
		Data[id].taskid = Data[id].taskid > 4 ? Data[id].taskid : 4;
		break;
		}
		else
		score=score_max;
		Sleep(speed);
	}lose:;
	
	end = clock();
	
	double time=((double)end-start)/CLK_TCK;//时间 

	gotoxy(31,0);
	score = score/((int)time%5)*2000;
	system("cls");
	color(6);
	printf("您的最终分数为：%d",score);
	MaxPoints = Max(MaxPoints, Data[id].data[4][3] + Data[id].data[4][4] + Data[id].data[4][5]);
	}
	else if(choose == 2){
		system("cls"); printf("当前关卡：吃豆人[关卡4]   当前用户: %s\n\n", Data[id].username);  
		printf("\t\t\t\t     Username   名次   总分   子关卡1   子关卡2   子关卡3  \n");
		ShowRank(4);
		system("pause");
	}
	//getchar();
	system("pause");
	return;
     //更新用户的最高关卡记录
}
