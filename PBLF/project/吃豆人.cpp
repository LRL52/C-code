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
//此处可修改敌人数和分数
int a[20][20] = {
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	{1,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,1},
	{1,0,0,0,0,1,0,0,0,0,1,1,0,0,0,1,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0,1},
	{1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,1},
	{1,0,0,0,0,0,1,1,0,0,0,0,0,0,1,0,0,0,0,1},
	{1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,1,0,0,0,0,1,0,1,0,0,1,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1,1,0,0,1},
	{1,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
};
//此处修改地图地形
const int dx[5] = { 0,1,-1,0,0 };
const int dy[5] = { 0,0,0,1,-1 };

void color(int a)//颜色函数
{
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),a);
}
void gotoxy(int x, int y) {//位置函数(行为x 列为y)
	COORD pos;
	pos.X=2*y;
	pos.Y=x;
	SetConsoleCursorPosition (GetStdHandle (STD_OUTPUT_HANDLE),pos);
}
int main()
{
	clock_t start,end;
	int choose;
	start = clock();

	int level;
	gotoxy(10,20);
	printf("1.选择难度\n2.查看历史记录\n");
	scanf("%d",&choose); 
	if(choose==1)
	{
	do{
	printf("请输入游戏难度：");
	scanf("%d", &level);
	}while(level==0);
	int number_enemy = 10 * level;
	int score_max = 20 * level;

	
	int enemy_x[number_enemy], enemy_y[number_enemy], player_x = 1, player_y = 1, point_x, point_y, score = score_max, before[number_enemy] = { 0 };
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
	}
	for (int i = 0; i < number_enemy; i++)
	{
		do {
			enemy_x[i] = rand() % 18 + 1;
			enemy_y[i] = rand() % 18 + 1;//敌人起始位置随机
		} while (a[enemy_x[i]][enemy_y[i]] != 0);
		a[enemy_x[i]][enemy_y[i]] = enemy;
	}

	while (1)
	{
		system("cls");
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
				case player:
					color(2);
					gotoxy(i,j);
					printf("@ ");
					break;
				case point:
					color(3);
					gotoxy(i,j);
					printf("o ");
					score--;
					break;
				case 5:
					color(4);
					gotoxy(i,j);
					printf("▲");
					break;
				case air:
					gotoxy(i,j);
					printf("  ");
					break;
				 
				}
			}
			printf("\n");
		}
		if (score == score_max)
		{
			color(6);
			printf("You Win!");
			break;
		}
		else
		{
			score = score_max;
		}
		if (_kbhit()) {
			int key = 0;
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
			if (a[player_x + dx[key]][player_y + dy[key]] != 1)
			{
				a[player_x][player_y] = 0;
				player_x += dx[key];
				player_y += dy[key];
				a[player_x][player_y] = player;
			}
		}//键盘改变移动方向
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
						enemy_x[i] += dx[d];
						enemy_y[i] += dy[d];
						before[i] = a[enemy_x[i]][enemy_y[i]];
						a[enemy_x[i]][enemy_y[i]] = enemy;
						
					}

				}goto outloop;
			}
		}outloop:;//敌人随机移动
		for (int i = 0; i < number_enemy; i++)
		{
			if (enemy_x[i] == player_x && enemy_y[i] == player_y)
			{
				color(4);
				printf("You Lose!");
				goto lose;
			}

		}//判断是否输掉游戏
		Sleep(300);
	}lose:;
	
	end = clock();
	
	double time=((double)end-start)/CLK_TCK;//时间 

	printf("%lf",score/time);//分 
	}
	getchar();
	
	return 0;

}

