#include "Subtask6.h" //�������ͷ�ļ�
#include "diynode.h"  //�����Զ���ṹ������,
#include <stdio.h>
#include <Windows.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
extern node Data[]; //������Ϸ����Data 
extern int id, taskid; //����id, taskid, idΪ��ǰ�û���Ӧ���������, ����Data[]�±�, taskid��ʾ��ǰ���ڽ��л򼴽�����Ĺؿ�, ��ܿ��ܻ��õ� 
//�����������д��������������ȵ�
#define ROW 29 //��Ϸ������
#define COL 20 //��Ϸ������

#define DOWN 80 //���������
#define LEFT 75 //���������
#define RIGHT 77 //���������

#define SPACE 32 //�ո��
#define ESC 27 //Esc��

static struct Face
{
	int data[ROW][COL + 10]; //���ڱ��ָ��λ���Ƿ��з��飨1Ϊ�У�0Ϊ�ޣ�
	int color[ROW][COL + 10]; //���ڼ�¼ָ��λ�õķ�����ɫ����
}face;

static struct Block
{
	int space[4][4];
}block[7][4]; //���ڴ洢7�ֻ�����״����ĸ��Ե�4����̬����Ϣ����28��
//���ع��
static void HideCursor();
//�����ת
static void CursorJump(int x, int y);
//��ʼ������
static void InitInterface();
//��ʼ��������Ϣ
static void InitBlockInfo();
//��ɫ����
static void color(int num);
//��������
static void DrawBlock(int shape, int form, int x, int y);
//�ո񸲸�
static void DrawSpace(int shape, int form, int x, int y);
//�Ϸ����ж�
static int IsLegal(int shape, int form, int x, int y);
//�жϵ÷������
static int JudeFunc();
//��Ϸ�����߼�����
static void StartGame();
//�ؿ�ѡ��
static void Level(); 
//��ȡ��� 
static void gotoxy(int x , int y);
//��ӡ����
static void title();
static void flower();


static int grade,level; //ȫ�ֱ���

#define max Data[id].data[6][3]
#define MaxPoints Data[id].data[6][1]
void Subtask6(){ //���潫�������Ϸ���, ȷ��return��taskid����Ϊ���ʵ�ֵ, 1~Gamecnt��ʾ��Ӧ�ؿ�, -1��ʾ�˳���Ϸ
    #pragma warning (disable:4996) //��������
    system("cls"); Data[id].data[6][0] = 5;
	title();
	flower();
	Level();
	system("cls");
	grade = 0; //��ʼ������
	system("title ����˹����"); //����cmd���ڵ�����
	system("mode con lines=29 cols=60"); //����cmd���ڵĴ�С
	HideCursor(); //���ع��
	//ReadGrade(); //���ļ���ȡ��߷ֵ�max����	
	InitInterface(); //��ʼ������
	InitBlockInfo(); //��ʼ��������Ϣ
	srand((unsigned int)time(NULL)); //������������ɵ����

	StartGame(); //��ʼ��Ϸ
	return;
}

//��ɫ����
void color(int c)
{
	switch (c)
	{
	case 0:
		c = 13; //��T���η�������Ϊ��ɫ
		break;
	case 1:
	case 2:
		c = 12; //��L���κ͡�J���η�������Ϊ��ɫ
		break;
	case 3:
	case 4:
		c = 10; //��Z���κ͡�S���η�������Ϊ��ɫ
		break;
	case 5:
		c = 14; //��O���η�������Ϊ��ɫ
		break;
	case 6:
		c = 11; //��I���η�������Ϊǳ��ɫ
		break;
	default:
		c = 7; //����Ĭ������Ϊ��ɫ
		break;
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), c); //��ɫ����
	//ע��SetConsoleTextAttribute��һ��API��Ӧ�ó����̽ӿڣ�
}


//��ȡ��� 
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
 	printf("Ȥ ζ �� �� ˹ �� ��\n");
 	color(11);
 	gotoxy(18,5);
 	printf("��");
 	gotoxy(18,6);
 	printf("����");
 	gotoxy(18,7);
 	printf("��");
    
	color(12);
 	gotoxy(26,6);
 	printf("����");
 	gotoxy(28,7);
 	printf("����");
	
	color(10);
 	gotoxy(36,6);
 	printf("����");
 	gotoxy(36,7);
 	printf("����");
	 
	color(13);
	gotoxy(45,5);
	printf("��");
	gotoxy(45,6);
	printf("��");
	gotoxy(45,7);
	printf("��");
	gotoxy(45,8);
	printf("��");
	
	color(12);
	gotoxy(56,6);
	printf("��");
	gotoxy(52,7);
	printf("������"); 	
 	
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
	printf("�� ��");
 }

//���ع��
void HideCursor()
{
	CONSOLE_CURSOR_INFO curInfo; //��������Ϣ�Ľṹ�����
	curInfo.dwSize = 1;  //���û��ֵ�Ļ������ع����Ч
	curInfo.bVisible = FALSE; //���������Ϊ���ɼ�
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE); //��ȡ����̨���
	SetConsoleCursorInfo(handle, &curInfo); //���ù����Ϣ
}
//�����ת
void CursorJump(int x, int y)
{
	COORD pos; //������λ�õĽṹ�����
	pos.X = x; //����������
	pos.Y = y; //����������
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE); //��ȡ����̨���
	SetConsoleCursorPosition(handle, pos); //���ù��λ��
}
//��ʼ������
void InitInterface()
{
	color(7); //��ɫ����Ϊ��ɫ
	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < COL + 10; j++)
		{
			if (j == 0 || j == COL - 1 || j == COL + 9)
			{
				face.data[i][j] = 1; //��Ǹ�λ���з���
				CursorJump(2 * j, i);
				printf("��");
			}
			else if (i == ROW - 1)
			{
				face.data[i][j] = 1; //��Ǹ�λ���з���
				printf("��");
			}
			else
				face.data[i][j] = 0; //��Ǹ�λ���޷���
		}
	}
	for (int i = COL; i < COL + 10; i++)
	{
		face.data[8][i] = 1; //��Ǹ�λ���з���
		CursorJump(2 * i, 8);
		printf("��");
	}

	CursorJump(2 * COL, 1);
	printf("��һ�����飺");

	CursorJump(2 * COL + 4, ROW - 19);
	printf("���ƣ���");

	CursorJump(2 * COL + 4, ROW - 17);
	printf("���ƣ���");

	CursorJump(2 * COL + 4, ROW - 15);
	printf("���٣���");

	CursorJump(2 * COL + 4, ROW - 13);
	printf("��ת���ո�");

	CursorJump(2 * COL + 4, ROW - 11);
	printf("��ͣ: S");

	CursorJump(2 * COL + 4, ROW - 9);
	printf("�˳�: Esc");

	CursorJump(2 * COL + 4, ROW - 7);
	printf("�ص��˵�:R");

	CursorJump(2 * COL + 4, ROW - 5);
	printf("��߼�¼:%d", max);
	MaxPoints = Max(MaxPoints, Data[id].data[6][3] + Data[id].data[6][4] + Data[id].data[6][5]);

	CursorJump(2 * COL + 4, ROW - 3);
	printf("��ǰ������%d", grade);
}
//��ʼ��������Ϣ
void InitBlockInfo()
{
	//��T����
	for (int i = 0; i <= 2; i++)
		block[0][0].space[1][i] = 1;
	block[0][0].space[2][1] = 1;

	//��L����
	for (int i = 1; i <= 3; i++)
		block[1][0].space[i][1] = 1;
	block[1][0].space[3][2] = 1;

	//��J����
	for (int i = 1; i <= 3; i++)
		block[2][0].space[i][2] = 1;
	block[2][0].space[3][1] = 1;

	for (int i = 0; i <= 1; i++)
	{
		//��Z����
		block[3][0].space[1][i] = 1;
		block[3][0].space[2][i + 1] = 1;
		//��S����
		block[4][0].space[1][i + 1] = 1;
		block[4][0].space[2][i] = 1;
		//��O����
		block[5][0].space[1][i + 1] = 1;
		block[5][0].space[2][i + 1] = 1;
	}

	//��I����
	for (int i = 0; i <= 3; i++)
		block[6][0].space[i][1] = 1;

	int temp[4][4];
	for (int shape = 0; shape < 7; shape++) //7����״
	{
		for (int form = 0; form < 3; form++) //4����̬���Ѿ�����һ�֣�����ÿ����������3�֣�
		{
			//��ȡ��form����̬
			for (int i = 0; i < 4; i++)
			{
				for (int j = 0; j < 4; j++)
				{
					temp[i][j] = block[shape][form].space[i][j];
				}
			}
			//����form����̬˳ʱ����ת���õ���form+1����̬
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

//��������
void DrawBlock(int shape, int form, int x, int y)
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (block[shape][form].space[i][j] == 1) //�����λ���з���
			{
				CursorJump(2 * (x + j), y + i); //�����ת��ָ��λ��
				printf("��"); //�������
			}
		}
	}
}
//�ո񸲸�
void DrawSpace(int shape, int form, int x, int y)
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (block[shape][form].space[i][j] == 1) //�����λ���з���
			{
				CursorJump(2 * (x + j), y + i); //�����ת��ָ��λ��
				printf("  "); //��ӡ�ո񸲸ǣ������ո�
			}
		}
	}
}
//�Ϸ����ж�
int IsLegal(int shape, int form, int x, int y)
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			//����������µ�λ�ñ������Ѿ��з����ˣ��򲻺Ϸ�
			if ((block[shape][form].space[i][j] == 1) && (face.data[y + i][x + j] == 1))
				return 0; //���Ϸ�
		}
	}
	return 1; //�Ϸ�
}
//�жϵ÷������
int JudeFunc()
{
	//�ж��Ƿ�÷�
	for (int i = ROW - 2; i > 4; i--)
	{
		int sum = 0; //��¼��i�еķ������
		for (int j = 1; j < COL - 1; j++)
		{
			sum += face.data[i][j]; //ͳ�Ƶ�i�еķ������
		}
		if (sum == 0) //����û�з��飬�������ж����ϵĲ�Σ������ټ����ж��Ƿ�÷֣�
			break; //����ѭ��
		if (sum == COL - 2) //����ȫ�Ƿ��飬�ɵ÷�
		{
			grade += 1000; //��һ�м�1000��
			color(7); //��ɫ����Ϊ��ɫ
			CursorJump(2 * COL + 4, ROW - 3); //�����ת����ʾ��ǰ������λ��
			printf("��ǰ������%d", grade); //���µ�ǰ����
			for (int j = 1; j < COL - 1; j++) //����÷��еķ�����Ϣ
			{
				face.data[i][j] = 0; //��λ�õ÷ֺ���������Ϊ�޷���
				CursorJump(2 * j, i); //�����ת����λ��
				printf("  "); //��ӡ�ո񸲸ǣ������ո�
			}
			//�ѱ���������������������Ųһ��
			for (int m = i; m >1; m--)
			{
				sum = 0; //��¼��һ�еķ������
				for (int n = 1; n < COL - 1; n++)
				{
					sum += face.data[m - 1][n]; //ͳ����һ�еķ������
					face.data[m][n] = face.data[m - 1][n]; //����һ�з���ı�ʶ�Ƶ���һ��
					face.color[m][n] = face.color[m - 1][n]; //����һ�з������ɫ����Ƶ���һ��
					if (face.data[m][n] == 1) //��һ�����������Ƿ��飬��ӡ����
					{
						CursorJump(2 * n, m); //�����ת����λ��
						color(face.color[m][n]); //��ɫ����Ϊ�÷������ɫ
						printf("��"); //��ӡ����
					}
					else //��һ�����������ǿո񣬴�ӡ�ո�
					{
						CursorJump(2 * n, m); //�����ת����λ��
						printf("  "); //��ӡ�ո������ո�
					}
				}
				if (sum == 0) //��һ����������ȫ�ǿո������ٽ��ϲ�ķ��������ƶ����ƶ�������
					return 1; //����1����ʾ������øú��������жϣ��ƶ������Ŀ��ܻ������У�
			}
		}
	}
	//�ж���Ϸ�Ƿ����
	for (int j = 1; j < COL - 1; j++)
	{
		if (face.data[1][j] == 1) //�����з�����ڣ��Ե�1��Ϊ���㣬���ǵ�0�У�
		{
			Sleep(1000); //������ҷ�Ӧʱ��
			system("cls"); //�����Ļ
			color(7); //��ɫ����Ϊ��ɫ
			CursorJump(2 * (COL / 3), ROW / 2 - 3);
			if (grade>max)
			{
				printf("��ϲ�������߼�¼����߼�¼����Ϊ%d", grade);
				max = grade;
				//WriteGrade();
			}
			else if (grade == max)
			{
				printf("����߼�¼��ƽ�������ٴ��Ѽ�", grade);
			}
			else
			{
				printf("��������ͣ���ǰ����߼�¼���%d", max - grade);
			}
			CursorJump(2 * (COL / 3), ROW / 2);
			printf("GAME OVER");
			while (1)
			{
				char ch;
				CursorJump(2 * (COL / 3), ROW / 2 + 3);
				printf("����һ��(y):\n");
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
					printf("ѡ��������ٴ�ѡ��");
				}
			}
		}
	}
	return 0; //�жϽ����������ٵ��øú��������ж�
}
//��Ϸ�����߼�����
void StartGame()
{
	int shape = rand() % 7, form = rand() % 4; //�����ȡ�������״����̬
	while (1)
	{
		int t = 0;
		int nextShape = rand() % 7, nextForm = rand() % 4; //�����ȡ��һ���������״����̬
		int x = COL / 2 - 2, y = 0; //�����ʼ����λ�õĺ�������
		color(nextShape); //��ɫ����Ϊ��һ���������ɫ
		DrawBlock(nextShape, nextForm, COL + 3, 3); //����һ��������ʾ�����Ͻ�
		while (1)
		{
			color(shape); //��ɫ����Ϊ��ǰ��������ķ���
			DrawBlock(shape, form, x, y); //���÷�����ʾ�ڳ�ʼ����λ��
			if (t == 0)
			{
				t = level; //����tԽС����������Խ�죨���Ը��ݴ�������Ϸ�Ѷȣ�
			}
			while (--t)
			{
				if (kbhit() != 0) //�����̱��û������˳�ѭ��
					break;
			}
			if (t == 0) //����δ���û�
			{
				if (IsLegal(shape, form, x, y + 1) == 0) //����������Ͳ��Ϸ��ˣ��Ѿ�����ײ���
				{
					//����ǰ�������Ϣ¼��face����
					//face:��¼�����ÿ��λ���Ƿ��з��飬���з��黹���¼��λ�÷������ɫ��
					for (int i = 0; i < 4; i++)
					{
						for (int j = 0; j < 4; j++)
						{
							if (block[shape][form].space[i][j] == 1)
							{
								face.data[y + i][x + j] = 1; //����λ�ñ��Ϊ�з���
								face.color[y + i][x + j] = shape; //��¼�÷������ɫ��ֵ
							}
						}
					}
					while (JudeFunc()); //�жϴ˴η��������Ƿ�÷��Լ���Ϸ�Ƿ����
					break; //������ǰ��ѭ����׼��������һ�����������
				}
				else //δ���ײ�
				{
					DrawSpace(shape, form, x, y); //�ÿո񸲸ǵ�ǰ��������λ��
					y++; //��������������һ����ʾ����ʱ���൱��������һ���ˣ�
				}
			}
			else //���̱��û�
			{
				char ch = getch(); //��ȡkeycode
				switch (ch)
				{
				case DOWN: //���������
					if (IsLegal(shape, form, x, y + 1) == 1) //�жϷ��������ƶ�һλ���Ƿ�Ϸ�
					{
						//���������Ϸ��Ž������²���
						DrawSpace(shape, form, x, y); //�ÿո񸲸ǵ�ǰ��������λ��
						y++; //��������������һ����ʾ����ʱ���൱��������һ���ˣ�
					}
					break;
				case LEFT: //���������
					if (IsLegal(shape, form, x - 1, y) == 1) //�жϷ��������ƶ�һλ���Ƿ�Ϸ�
					{
						//�������ƺ�Ϸ��Ž������²���
						DrawSpace(shape, form, x, y); //�ÿո񸲸ǵ�ǰ��������λ��
						x--; //�������Լ�����һ����ʾ����ʱ���൱��������һ���ˣ�
					}
					break;
				case RIGHT: //���������
					if (IsLegal(shape, form, x + 1, y) == 1) //�жϷ��������ƶ�һλ���Ƿ�Ϸ�
					{
						//�������ƺ�Ϸ��Ž������²���
						DrawSpace(shape, form, x, y); //�ÿո񸲸ǵ�ǰ��������λ��
						x++; //��������������һ����ʾ����ʱ���൱��������һ���ˣ�
					}
					break;
				case SPACE: //�ո��
					if (IsLegal(shape, (form + 1) % 4, x, y + 1) == 1) //�жϷ�����ת���Ƿ�Ϸ�
					{
						//������ת��Ϸ��Ž������²���
						DrawSpace(shape, form, x, y); //�ÿո񸲸ǵ�ǰ��������λ��
						y++; //�������������ܲ���ԭ����ת�ɣ�
						form = (form + 1) % 4; //�������̬��������һ����ʾ����ʱ���൱����ת�ˣ�
					}
					break;
				case ESC: //Esc���� 
					system("cls"); //�����Ļ
					color(7);
					CursorJump(COL, ROW / 2);
					printf("  ��Ϸ����  ");
					CursorJump(COL, ROW / 2 + 2);
					Subtask6(); //��������
				case 's':
				case 'S':  //��ͣ
					system("pause>nul"); //��ͣ���������������
					break;
				case 'r':
				case 'R': //�ص��˵� 
					system("cls"); //�����Ļ
					Subtask6(); //����ִ��������
				}
			}
		}
		shape = nextShape, form = nextForm; //��ȡ��һ���������Ϣ
		DrawSpace(nextShape, nextForm, COL + 3, 3); //�����Ͻǵķ�����Ϣ�ÿո񸲸�
	}
}
//�ؿ�ѡ��
void Level() 
{
  int n;
  color(7);
  CursorJump(1 , 1);
  printf("��ӭ��������˹����\n");
  CursorJump(1 , 2);
  printf("��ѡ��[1 2 3 4]:[]\b\b");
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
