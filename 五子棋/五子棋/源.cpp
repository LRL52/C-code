#include<stdio.h>
#include<graphics.h>
#include<easyx.h>
#include<stdlib.h>
#include<stdbool.h>
#define gap 43//棋子间隔
#define first_position_x 20//起始x坐标
#define first_position_y 200//起始y坐标
#define black 1//黑子
#define white 2//白子
#define chess_r 20//棋子半径

IMAGE map;


int judge_diagonal(int *a[], int x, int y)
{
	int i = 0,k = 0;

	if (a[x][y] == 1 &&a[++x][++y] == 1)
	{
		i++;

	}

	if (a[x][y] == 2 && a[++x][++y] == 2)
	{
		k++;
	}
	if (i == 5)
	{
		printf("黑方胜利");
		return 0;
	}
	else if (k == 5)
	{
		printf("白方胜利");
		return 0;
	}
	return 1;
}//判断斜对角线棋子个数
int judge_row(int* a[], int x, int y)
{
	int i = 0, k = 0;

	if (a[x][y] == 1 && a[++x][y] == 1)
	{
		i++;

	}

	if (a[x][y] == 2 && a[++x][y] == 2)
	{
		k++;
	}
	if (i == 5)
	{
		printf("黑方胜利");
		return 0;
	}
	else if (k == 5)
	{
		printf("白方胜利");
		return 0;
	}
	return 1;
}//判断行
int judge_line(int* a[], int x, int y)
{
	int i = 0, k = 0;

	if (a[x][y] == 1 && a[x][++y] == 1)//判断列
	{
		i++;

	}

	if (a[x][y] == 2 && a[x][++y] == 2)
	{
		k++;
	}
	if (i == 5)
	{
		printf("黑方胜利");
		return 0;
	}
	else if (k == 5)
	{
		printf("白方胜利");
		return 0;
	}
	return 1;
}

int main()
{
	initgraph(480,750,EW_SHOWCONSOLE);//屏幕设置
	
	loadimage(&map,_T ("./chess.jpg"),480,750);

	putimage(0, 0, &map);//棋盘的输出

	int x[13], y[13];

	for (int i = 0; i < 13; i++)//导入点在图片中的像素坐标
	{
		x[i] = first_position_x + i * gap;
		y[i] = first_position_y + i * gap;
	}

	int chess[13][13] = {0};

	bool CHESS[13][13] = { false };

	int current_x, current_y, n = 0;


	while (judge_diagonal(*chess[], current_x, current_y)&& judge_row(*chess[], current_x, current_y)&& judge_line(*chess[], current_x, current_y))//判断是否胜利
	{
		if (MouseHit() && n % 2 == 0)//黑棋落子
		{
			n++;//黑白交替

			MOUSEMSG msg = GetMouseMsg();

			switch (msg.uMsg)
			{
			case WM_LBUTTONDOWN:
				current_x = msg.x;
				current_y = msg.y;
				if (CHESS[current_x][current_y] == 1)//防重复落子
					break;
				else 
				{
					setfillcolor(BLACK);
					fillcircle(x[(current_x - first_position_x) / first_position_x], y[(current_y - first_position_y) / first_position_y], chess_r);
					CHESS[current_x][current_y] = 1;
					chess[current_x][current_y] = 1;
					break;
				}
			default:
				break;
			}

		}
		if (MouseHit() && n % 2 == 1)//白棋落子
		{
			n++;//黑白交替

			MOUSEMSG msg = GetMouseMsg();

			switch (msg.uMsg)
			{
			case WM_LBUTTONDOWN:
				current_x = msg.x;
				current_y = msg.y;
				if (CHESS[current_x][current_y] == 1)//防重复落子
					break;
				else
				{
					setfillcolor(WHITE);
					fillcircle(x[(current_x - first_position_x) / first_position_x], y[(current_y - first_position_y) / first_position_y], chess_r);
					CHESS[current_x][current_y] = 1;
					chess[current_x][current_y] = 2;
					break;
				}
			default:
				break;
			}

		}
	}
	getchar();//防闪退
	closegraph();//关闭弹窗
	return 0;
}