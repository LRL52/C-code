#include<stdio.h>
#include<graphics.h>
#include<easyx.h>
#include<stdlib.h>
#include<stdbool.h>
#define gap 43//���Ӽ��
#define first_position_x 20//��ʼx����
#define first_position_y 200//��ʼy����
#define black 1//����
#define white 2//����
#define chess_r 20//���Ӱ뾶

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
		printf("�ڷ�ʤ��");
		return 0;
	}
	else if (k == 5)
	{
		printf("�׷�ʤ��");
		return 0;
	}
	return 1;
}//�ж�б�Խ������Ӹ���
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
		printf("�ڷ�ʤ��");
		return 0;
	}
	else if (k == 5)
	{
		printf("�׷�ʤ��");
		return 0;
	}
	return 1;
}//�ж���
int judge_line(int* a[], int x, int y)
{
	int i = 0, k = 0;

	if (a[x][y] == 1 && a[x][++y] == 1)//�ж���
	{
		i++;

	}

	if (a[x][y] == 2 && a[x][++y] == 2)
	{
		k++;
	}
	if (i == 5)
	{
		printf("�ڷ�ʤ��");
		return 0;
	}
	else if (k == 5)
	{
		printf("�׷�ʤ��");
		return 0;
	}
	return 1;
}

int main()
{
	initgraph(480,750,EW_SHOWCONSOLE);//��Ļ����
	
	loadimage(&map,_T ("./chess.jpg"),480,750);

	putimage(0, 0, &map);//���̵����

	int x[13], y[13];

	for (int i = 0; i < 13; i++)//�������ͼƬ�е���������
	{
		x[i] = first_position_x + i * gap;
		y[i] = first_position_y + i * gap;
	}

	int chess[13][13] = {0};

	bool CHESS[13][13] = { false };

	int current_x, current_y, n = 0;


	while (judge_diagonal(*chess[], current_x, current_y)&& judge_row(*chess[], current_x, current_y)&& judge_line(*chess[], current_x, current_y))//�ж��Ƿ�ʤ��
	{
		if (MouseHit() && n % 2 == 0)//��������
		{
			n++;//�ڰ׽���

			MOUSEMSG msg = GetMouseMsg();

			switch (msg.uMsg)
			{
			case WM_LBUTTONDOWN:
				current_x = msg.x;
				current_y = msg.y;
				if (CHESS[current_x][current_y] == 1)//���ظ�����
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
		if (MouseHit() && n % 2 == 1)//��������
		{
			n++;//�ڰ׽���

			MOUSEMSG msg = GetMouseMsg();

			switch (msg.uMsg)
			{
			case WM_LBUTTONDOWN:
				current_x = msg.x;
				current_y = msg.y;
				if (CHESS[current_x][current_y] == 1)//���ظ�����
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
	getchar();//������
	closegraph();//�رյ���
	return 0;
}