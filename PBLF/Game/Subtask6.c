#include "Subtask6.h" //引入你的头文件
#include "diynode.h"  //引入自定义结构体类型,
#include <stdio.h>
#include <Windows.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
extern node Data[]; //共享游戏数据Data 
extern int id, taskid; //共享id, taskid, id为当前用户对应的数字序号, 用作Data[]下标, taskid表示当前正在进行或即将进入的关卡, 你很可能会用到 
//你可以在下面写函数，定义变量等等
#define ROW 29 //游戏区行数
#define COL 20 //游戏区列数

#define DOWN 80 //方向键：下
#define LEFT 75 //方向键：左
#define RIGHT 77 //方向键：右

#define SPACE 32 //空格键
#define ESC 27 //Esc键

static struct Face
{
	int data[ROW][COL + 10]; //用于标记指定位置是否有方块（1为有，0为无）
	int color[ROW][COL + 10]; //用于记录指定位置的方块颜色编码
}face;

static struct Block
{
	int space[4][4];
}block[7][4]; //用于存储7种基本形状方块的各自的4种形态的信息，共28种
//隐藏光标
static void HideCursor();
//光标跳转
static void CursorJump(int x, int y);
//初始化界面
static void InitInterface();
//初始化方块信息
static void InitBlockInfo();
//颜色设置
static void color(int num);
//画出方块
static void DrawBlock(int shape, int form, int x, int y);
//空格覆盖
static void DrawSpace(int shape, int form, int x, int y);
//合法性判断
static int IsLegal(int shape, int form, int x, int y);
//判断得分与结束
static int JudeFunc();
//游戏主体逻辑函数
static void StartGame();
//关卡选择
static void Level(); 
//获取光标 
static void gotoxy(int x , int y);
//打印标题
static void title();
static void flower();


static int grade,level; //全局变量

#define max Data[id].data[6][3]
#define MaxPoints Data[id].data[6][1]
void Subtask6(){ //下面将是你的游戏入口, 确保return后将taskid更改为合适的值, 1~Gamecnt表示对应关卡, -1表示退出游戏
    #pragma warning (disable:4996) //消除警告
    system("cls"); Data[id].data[6][0] = 5;
	title();
	flower();
	Level();
	system("cls");
	grade = 0; //初始化变量
	system("title 俄罗斯方块"); //设置cmd窗口的名字
	system("mode con lines=29 cols=60"); //设置cmd窗口的大小
	HideCursor(); //隐藏光标
	//ReadGrade(); //从文件读取最高分到max变量	
	InitInterface(); //初始化界面
	InitBlockInfo(); //初始化方块信息
	srand((unsigned int)time(NULL)); //设置随机数生成的起点

	StartGame(); //开始游戏
	return;
}

//颜色设置
void color(int c)
{
	switch (c)
	{
	case 0:
		c = 13; //“T”形方块设置为紫色
		break;
	case 1:
	case 2:
		c = 12; //“L”形和“J”形方块设置为红色
		break;
	case 3:
	case 4:
		c = 10; //“Z”形和“S”形方块设置为绿色
		break;
	case 5:
		c = 14; //“O”形方块设置为黄色
		break;
	case 6:
		c = 11; //“I”形方块设置为浅蓝色
		break;
	default:
		c = 7; //其他默认设置为白色
		break;
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), c); //颜色设置
	//注：SetConsoleTextAttribute是一个API（应用程序编程接口）
}


//获取光标 
void gotoxy(int x , int y)
{
 	COORD pos;
 	pos.X = x;
 	pos.Y = y;
 	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
 }
 
 void title()
{
 	system("mode con lines=30 cols=125");
	 color(13);
 	gotoxy(28,3);
 	printf("趣 味 俄 罗 斯 方 块\n");
 	color(11);
 	gotoxy(18,5);
 	printf("■");
 	gotoxy(18,6);
 	printf("■■");
 	gotoxy(18,7);
 	printf("■");
    
	color(12);
 	gotoxy(26,6);
 	printf("■■");
 	gotoxy(28,7);
 	printf("■■");
	
	color(10);
 	gotoxy(36,6);
 	printf("■■");
 	gotoxy(36,7);
 	printf("■■");
	 
	color(13);
	gotoxy(45,5);
	printf("■");
	gotoxy(45,6);
	printf("■");
	gotoxy(45,7);
	printf("■");
	gotoxy(45,8);
	printf("■");
	
	color(12);
	gotoxy(56,6);
	printf("■");
	gotoxy(52,7);
	printf("■■■"); 	
 	
 }
 
void flower()
{
 	gotoxy(66,11);
 	color(12);
 	printf("(_)");
 	
 	gotoxy(64,12);
 	printf("(_)");
 	
 	gotoxy(68,12);
 	printf("(_)");
 	
 	gotoxy(66,13);
 	printf("(_)");
 	
 	gotoxy(67,12);
 	color(6);
 	printf("@");
 	
	gotoxy(72,10);
	color(13);
	printf("(_)");
	
	gotoxy(76,10);
	printf("(_)");
	
	gotoxy(74,9);
	printf("(_)");
	
	gotoxy(74,11);
	printf("(_)");
	
	gotoxy(75,10);
	color(6);
	printf("@");
	
	gotoxy(71,12);
	printf("|");
	
	gotoxy(72,11);
	printf("/");
	
	gotoxy(70,13);
	printf("\\|");
	
	gotoxy(70,14);
	printf("`|/");
	
	gotoxy(70,15);
	printf("\\|");
	
	gotoxy(71,16);
	printf("| /");
	
	gotoxy(71,17);
	printf("|");
	
	gotoxy(67,17);
	color(10);
	printf("\\\\\\\\");
	
	gotoxy(73,17);
	printf("//");
	
	gotoxy(67,18);
	color(2);
	printf("^^^^^^^^");
	
	gotoxy(65,19);
	color(5);
	printf("炎 年");
 }

//隐藏光标
void HideCursor()
{
	CONSOLE_CURSOR_INFO curInfo; //定义光标信息的结构体变量
	curInfo.dwSize = 1;  //如果没赋值的话，隐藏光标无效
	curInfo.bVisible = FALSE; //将光标设置为不可见
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE); //获取控制台句柄
	SetConsoleCursorInfo(handle, &curInfo); //设置光标信息
}
//光标跳转
void CursorJump(int x, int y)
{
	COORD pos; //定义光标位置的结构体变量
	pos.X = x; //横坐标设置
	pos.Y = y; //纵坐标设置
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE); //获取控制台句柄
	SetConsoleCursorPosition(handle, pos); //设置光标位置
}
//初始化界面
void InitInterface()
{
	color(7); //颜色设置为白色
	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < COL + 10; j++)
		{
			if (j == 0 || j == COL - 1 || j == COL + 9)
			{
				face.data[i][j] = 1; //标记该位置有方块
				CursorJump(2 * j, i);
				printf("■");
			}
			else if (i == ROW - 1)
			{
				face.data[i][j] = 1; //标记该位置有方块
				printf("■");
			}
			else
				face.data[i][j] = 0; //标记该位置无方块
		}
	}
	for (int i = COL; i < COL + 10; i++)
	{
		face.data[8][i] = 1; //标记该位置有方块
		CursorJump(2 * i, 8);
		printf("■");
	}

	CursorJump(2 * COL, 1);
	printf("下一个方块：");

	CursorJump(2 * COL + 4, ROW - 19);
	printf("左移：←");

	CursorJump(2 * COL + 4, ROW - 17);
	printf("右移：→");

	CursorJump(2 * COL + 4, ROW - 15);
	printf("加速：↓");

	CursorJump(2 * COL + 4, ROW - 13);
	printf("旋转：空格");

	CursorJump(2 * COL + 4, ROW - 11);
	printf("暂停: S");

	CursorJump(2 * COL + 4, ROW - 9);
	printf("退出: Esc");

	CursorJump(2 * COL + 4, ROW - 7);
	printf("回到菜单:R");

	CursorJump(2 * COL + 4, ROW - 5);
	printf("最高纪录:%d", max);
	MaxPoints = Max(MaxPoints, Data[id].data[6][3] + Data[id].data[6][4] + Data[id].data[6][5]);

	CursorJump(2 * COL + 4, ROW - 3);
	printf("当前分数：%d", grade);
}
//初始化方块信息
void InitBlockInfo()
{
	//“T”形
	for (int i = 0; i <= 2; i++)
		block[0][0].space[1][i] = 1;
	block[0][0].space[2][1] = 1;

	//“L”形
	for (int i = 1; i <= 3; i++)
		block[1][0].space[i][1] = 1;
	block[1][0].space[3][2] = 1;

	//“J”形
	for (int i = 1; i <= 3; i++)
		block[2][0].space[i][2] = 1;
	block[2][0].space[3][1] = 1;

	for (int i = 0; i <= 1; i++)
	{
		//“Z”形
		block[3][0].space[1][i] = 1;
		block[3][0].space[2][i + 1] = 1;
		//“S”形
		block[4][0].space[1][i + 1] = 1;
		block[4][0].space[2][i] = 1;
		//“O”形
		block[5][0].space[1][i + 1] = 1;
		block[5][0].space[2][i + 1] = 1;
	}

	//“I”形
	for (int i = 0; i <= 3; i++)
		block[6][0].space[i][1] = 1;

	int temp[4][4];
	for (int shape = 0; shape < 7; shape++) //7种形状
	{
		for (int form = 0; form < 3; form++) //4种形态（已经有了一种，这里每个还需增加3种）
		{
			//获取第form种形态
			for (int i = 0; i < 4; i++)
			{
				for (int j = 0; j < 4; j++)
				{
					temp[i][j] = block[shape][form].space[i][j];
				}
			}
			//将第form种形态顺时针旋转，得到第form+1种形态
			for (int i = 0; i < 4; i++)
			{
				for (int j = 0; j < 4; j++)
				{
					block[shape][form + 1].space[i][j] = temp[3 - j][i];
				}
			}
		}
	}
}

//画出方块
void DrawBlock(int shape, int form, int x, int y)
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (block[shape][form].space[i][j] == 1) //如果该位置有方块
			{
				CursorJump(2 * (x + j), y + i); //光标跳转到指定位置
				printf("■"); //输出方块
			}
		}
	}
}
//空格覆盖
void DrawSpace(int shape, int form, int x, int y)
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (block[shape][form].space[i][j] == 1) //如果该位置有方块
			{
				CursorJump(2 * (x + j), y + i); //光标跳转到指定位置
				printf("  "); //打印空格覆盖（两个空格）
			}
		}
	}
}
//合法性判断
int IsLegal(int shape, int form, int x, int y)
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			//如果方块落下的位置本来就已经有方块了，则不合法
			if ((block[shape][form].space[i][j] == 1) && (face.data[y + i][x + j] == 1))
				return 0; //不合法
		}
	}
	return 1; //合法
}
//判断得分与结束
int JudeFunc()
{
	//判断是否得分
	for (int i = ROW - 2; i > 4; i--)
	{
		int sum = 0; //记录第i行的方块个数
		for (int j = 1; j < COL - 1; j++)
		{
			sum += face.data[i][j]; //统计第i行的方块个数
		}
		if (sum == 0) //该行没有方块，无需再判断其上的层次（无需再继续判断是否得分）
			break; //跳出循环
		if (sum == COL - 2) //该行全是方块，可得分
		{
			grade += 1000; //满一行加1000分
			color(7); //颜色设置为白色
			CursorJump(2 * COL + 4, ROW - 3); //光标跳转到显示当前分数的位置
			printf("当前分数：%d", grade); //更新当前分数
			for (int j = 1; j < COL - 1; j++) //清除得分行的方块信息
			{
				face.data[i][j] = 0; //该位置得分后被清除，标记为无方块
				CursorJump(2 * j, i); //光标跳转到该位置
				printf("  "); //打印空格覆盖（两个空格）
			}
			//把被清除行上面的行整体向下挪一格
			for (int m = i; m >1; m--)
			{
				sum = 0; //记录上一行的方块个数
				for (int n = 1; n < COL - 1; n++)
				{
					sum += face.data[m - 1][n]; //统计上一行的方块个数
					face.data[m][n] = face.data[m - 1][n]; //将上一行方块的标识移到下一行
					face.color[m][n] = face.color[m - 1][n]; //将上一行方块的颜色编号移到下一行
					if (face.data[m][n] == 1) //上一行移下来的是方块，打印方块
					{
						CursorJump(2 * n, m); //光标跳转到该位置
						color(face.color[m][n]); //颜色设置为该方块的颜色
						printf("■"); //打印方块
					}
					else //上一行移下来的是空格，打印空格
					{
						CursorJump(2 * n, m); //光标跳转到该位置
						printf("  "); //打印空格（两个空格）
					}
				}
				if (sum == 0) //上一行移下来的全是空格，无需再将上层的方块向下移动（移动结束）
					return 1; //返回1，表示还需调用该函数进行判断（移动下来的可能还有满行）
			}
		}
	}
	//判断游戏是否结束
	for (int j = 1; j < COL - 1; j++)
	{
		if (face.data[1][j] == 1) //顶层有方块存在（以第1行为顶层，不是第0行）
		{
			Sleep(1000); //留给玩家反应时间
			system("cls"); //清空屏幕
			color(7); //颜色设置为白色
			CursorJump(2 * (COL / 3), ROW / 2 - 3);
			if (grade>max)
			{
				printf("恭喜你打破最高记录，最高记录更新为%d", grade);
				max = grade;
				//WriteGrade();
			}
			else if (grade == max)
			{
				printf("与最高记录持平，加油再创佳绩", grade);
			}
			else
			{
				printf("请继续加油，当前与最高记录相差%d", max - grade);
			}
			CursorJump(2 * (COL / 3), ROW / 2);
			printf("GAME OVER");
			while (1)
			{
				char ch;
				CursorJump(2 * (COL / 3), ROW / 2 + 3);
				printf("再来一局(y):\n");
				scanf("%c", &ch);
				if (ch == 'y' || ch == 'Y')
				{
					system("cls");
					Subtask6();
				}
				else if (ch == 'n' || ch == 'N')
				{
					system("cls");
					Subtask6();
				}
				else
				{
					CursorJump(2 * (COL / 3), ROW / 2 + 4);
					printf("选择错误，请再次选择");
				}
			}
		}
	}
	return 0; //判断结束，无需再调用该函数进行判断
}
//游戏主体逻辑函数
void StartGame()
{
	int shape = rand() % 7, form = rand() % 4; //随机获取方块的形状和形态
	while (1)
	{
		int t = 0;
		int nextShape = rand() % 7, nextForm = rand() % 4; //随机获取下一个方块的形状和形态
		int x = COL / 2 - 2, y = 0; //方块初始下落位置的横纵坐标
		color(nextShape); //颜色设置为下一个方块的颜色
		DrawBlock(nextShape, nextForm, COL + 3, 3); //将下一个方块显示在右上角
		while (1)
		{
			color(shape); //颜色设置为当前正在下落的方块
			DrawBlock(shape, form, x, y); //将该方块显示在初始下落位置
			if (t == 0)
			{
				t = level; //这里t越小，方块下落越快（可以根据此设置游戏难度）
			}
			while (--t)
			{
				if (kbhit() != 0) //若键盘被敲击，则退出循环
					break;
			}
			if (t == 0) //键盘未被敲击
			{
				if (IsLegal(shape, form, x, y + 1) == 0) //方块再下落就不合法了（已经到达底部）
				{
					//将当前方块的信息录入face当中
					//face:记录界面的每个位置是否有方块，若有方块还需记录该位置方块的颜色。
					for (int i = 0; i < 4; i++)
					{
						for (int j = 0; j < 4; j++)
						{
							if (block[shape][form].space[i][j] == 1)
							{
								face.data[y + i][x + j] = 1; //将该位置标记为有方块
								face.color[y + i][x + j] = shape; //记录该方块的颜色数值
							}
						}
					}
					while (JudeFunc()); //判断此次方块下落是否得分以及游戏是否结束
					break; //跳出当前死循环，准备进行下一个方块的下落
				}
				else //未到底部
				{
					DrawSpace(shape, form, x, y); //用空格覆盖当前方块所在位置
					y++; //纵坐标自增（下一次显示方块时就相当于下落了一格了）
				}
			}
			else //键盘被敲击
			{
				char ch = getch(); //读取keycode
				switch (ch)
				{
				case DOWN: //方向键：下
					if (IsLegal(shape, form, x, y + 1) == 1) //判断方块向下移动一位后是否合法
					{
						//方块下落后合法才进行以下操作
						DrawSpace(shape, form, x, y); //用空格覆盖当前方块所在位置
						y++; //纵坐标自增（下一次显示方块时就相当于下落了一格了）
					}
					break;
				case LEFT: //方向键：左
					if (IsLegal(shape, form, x - 1, y) == 1) //判断方块向左移动一位后是否合法
					{
						//方块左移后合法才进行以下操作
						DrawSpace(shape, form, x, y); //用空格覆盖当前方块所在位置
						x--; //横坐标自减（下一次显示方块时就相当于左移了一格了）
					}
					break;
				case RIGHT: //方向键：右
					if (IsLegal(shape, form, x + 1, y) == 1) //判断方块向右移动一位后是否合法
					{
						//方块右移后合法才进行以下操作
						DrawSpace(shape, form, x, y); //用空格覆盖当前方块所在位置
						x++; //横坐标自增（下一次显示方块时就相当于右移了一格了）
					}
					break;
				case SPACE: //空格键
					if (IsLegal(shape, (form + 1) % 4, x, y + 1) == 1) //判断方块旋转后是否合法
					{
						//方块旋转后合法才进行以下操作
						DrawSpace(shape, form, x, y); //用空格覆盖当前方块所在位置
						y++; //纵坐标自增（总不能原地旋转吧）
						form = (form + 1) % 4; //方块的形态自增（下一次显示方块时就相当于旋转了）
					}
					break;
				case ESC: //Esc键· 
					system("cls"); //清空屏幕
					color(7);
					CursorJump(COL, ROW / 2);
					printf("  游戏结束  ");
					CursorJump(COL, ROW / 2 + 2);
					Subtask6(); //结束程序
				case 's':
				case 'S':  //暂停
					system("pause>nul"); //暂停（按任意键继续）
					break;
				case 'r':
				case 'R': //回到菜单 
					system("cls"); //清空屏幕
					Subtask6(); //重新执行主函数
				}
			}
		}
		shape = nextShape, form = nextForm; //获取下一个方块的信息
		DrawSpace(nextShape, nextForm, COL + 3, 3); //将右上角的方块信息用空格覆盖
	}
}
//关卡选择
void Level() 
{
  int n;
  color(7);
  CursorJump(1 , 1);
  printf("欢迎来到俄罗斯方块\n");
  CursorJump(1 , 2);
  printf("请选择[1 2 3 4]:[]\b\b");
  color(14);
  scanf("%d", &n);
  switch (n)
  {
  	case 1:
  		level = 20000;
  	    break;
    case 2:
    	level = 17500;
    	break;
    case 3:
    	level = 15000;
    	break;
    case 4:
    	level = 12500;
    	break;
  }
}
