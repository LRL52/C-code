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
			puts("�����������ƣ��������룬��Ϸʧ��!!!");
			return;
		}
		printf("���������Guess:"); 
		scanf("%d", &x);
		++cnt;
		if(x > num) printf("̫����\n");
		else if(x < num) printf("̫С��\n");
		else{
			puts("Congratulations! ��¶�����!");
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
    puts("��ӭ��������С��Ϸ:");
	printf("LRL52�������һ��1��%d��������������������������LRL52�ᷴ����������������Դ�С\n", up);
	puts("����һ���Ĵ������ƣ�����Խ�ٸ���"); 
    if(Data[id].data[1][1]) printf("���ϴε���Ѽ�¼��%d��\n", Data[id].data[1][1]);
	int op;
	while(1){
		printf("1.��ʼ��Ϸ\n2.�л��ؿ�\n3.�˳���Ϸ\n");
		puts("���������ѡ��:"); 
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
