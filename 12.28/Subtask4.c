#include "Subtask4.h" //�������ͷ�ļ�
#include "diynode.h"  //�����Զ���ṹ������,
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
extern node Data[]; //������Ϸ����Data 
extern int id, taskid; //����id, taskid, idΪ��ǰ�û���Ӧ���������, ����Data[]�±�, taskid��ʾ��ǰ���ڽ��л򼴽�����Ĺؿ�, ��ܿ��ܻ��õ� 
//�����������д��������������ȵ�

//�˴����޸ĵ������ͷ���
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
//�˴��޸ĵ�ͼ����
const static int dx[5] = { 0,1,-1,0,0 };
const static int dy[5] = { 0,0,0,1,-1 };

static void color(int a)//��ɫ����
{
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),a);
}
static void gotoxy(int x, int y) {//λ�ú���(��Ϊx ��Ϊy)
	COORD pos;
	pos.X=2*y;
	pos.Y=x;
	SetConsoleCursorPosition (GetStdHandle (STD_OUTPUT_HANDLE),pos);
}

#define score Data[id].data[4][3]
#define MaxPoints Data[id].data[4][1]
void Subtask4(){ //���潫�������Ϸ���, ȷ��return��taskid����Ϊ���ʵ�ֵ, 1~Gamecnt��ʾ��Ӧ�ؿ�, -1��ʾ�˳���Ϸ
    if(score > 1000) Data[id].taskid = Data[id].taskid > 4 ? Data[id].taskid : 4;
	Data[id].data[4][0] = 5;
	//printf("%d %d\n", Data[id].data[4][4], Data[id].data[4][5]);
	clock_t start,end;
	int choose;
	int point_[20][20];
	memset(point_, 0, sizeof point_);
	start = clock();

	int level;
	printf("1.ѡ���Ѷ�\n2.�鿴��ʷ��¼\n");
	scanf("%d",&choose);
	if(choose!=1&&choose!=2)
	return EOF; 
	if(choose==1)
	{
	do{
	printf("��������Ϸ�Ѷȣ�");
	scanf("%d", &level);
	}while(level==0);
	MessageBox (NULL, "��ӭ�����Զ�����Ϸ��", "��ܰ��ʾ", MB_OK);
	system("cls");
	int number_enemy = 10 * level;
	int score_max = 10 * level;

	
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
			enemy_y[i] = rand() % 18 + 1;//������ʼλ�����
		} while (a[enemy_x[i]][enemy_y[i]] != 0);
		a[enemy_x[i]][enemy_y[i]] = enemy;
	}

			for (int i = 0; i < 20; i++)
		{
			for (int j = 0; j < 20; j++)
			{
				if (point[i][j] == point)
					score--;
				switch (a[i][j])
				{
				case stone_hard:
					color(1);
					gotoxy(i,j);
					printf("��");
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
				 
				}
			}
			printf("\n");
		}
		int key=1;
	while (1)
	{
		Sleep(300);
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
		
		}//���̸ı��ƶ�����
		if (a[player_x + dx[key]][player_y + dy[key]] != 1)
			{
				a[player_x][player_y] = 0;
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
						if(before[i]==0)
						{
							printf("  ");
						}
						else{
							color(3);
							printf("o ");
						}
						enemy_x[i] += dx[d];
						enemy_y[i] += dy[d];
						before[i] = a[enemy_x[i]][enemy_y[i]];
						gotoxy(enemy_x[i],enemy_y[i]);
						color(4);
						printf("��");
						
					}

				}goto outloop;
			}
		}outloop:;//��������ƶ�
		for (int i = 0; i < number_enemy; i++)
		{
			if (enemy_x[i] == player_x && enemy_y[i] == player_y)
			{
				color(4);
				MessageBox (NULL, "�����ˣ���", "��ܰ��ʾ", MB_OK);
				goto lose;
			}

		}//�ж��Ƿ������Ϸ
				for(int i=0;i<COL;i++)
		{
			for(int j=0;j<ROW;j++)
			{
				if(a[i][j]==point)
				{
					score--;
				}
			}
		}
		if(score==score_max)
		{
		MessageBox (NULL, "��Ӯ�ˣ���", "��ܰ��ʾ", MB_OK);
		Data[id].taskid = Data[id].taskid > 4 ? Data[id].taskid : 4;
		break;
		}
		else
		score=score_max;
		Sleep(300);
	}lose:;
	
	end = clock();
	
	double time=((double)end-start)/CLK_TCK;//ʱ�� 

	gotoxy(31,0);
	score = score/time*2000;
	printf("%d", score);//��
	MaxPoints = Max(MaxPoints, Data[id].data[4][3] + Data[id].data[4][4] + Data[id].data[4][5]);
	}
	else if(choose == 2){
		system("cls"); printf("��ǰ�ؿ����Զ���[�ؿ�4]   ��ǰ�û�: %s\n\n", Data[id].username);  
		printf("\t\t\t\t     Username   ����   �ܷ�   �ӹؿ�1   �ӹؿ�2   �ӹؿ�3  \n");
		ShowRank(4);
		system("pause");
	}
	//getchar();
	system("pause");
	return;
     //�����û�����߹ؿ���¼
}
