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
	printf("1.������ӹؿ���ˢ�֣�\n2.��������Ϸ����һ���ӹؿ�\n3.������Ϸ�˵�\n");
	printf("���������ѡ��:");
	scanf("%d", &op); fflush(stdin); return op; 
}*/ 

static void Game(int k){
	srand((unsigned)time(NULL));
	int num = 1LL * rand() * rand() * rand() % up[k] + 1, x, cnt = 0, maxcnt = lg[up[k]]+1;
	clock_t start = clock(), end; //int Points = 0; 
	if(k <= 2) printf("��ǰΪ�� %d ���ӹؿ����������ķ�Χ��1 - %d������������Ʋ���\n", k, up[k]); 
	else printf("��ǰΪ�� %d ��(BOSS)�ӹؿ����������ķ�Χ��1 - %d�������ֻ��%d�β²����\n", k, up[k], maxcnt); 
	while(1){
		if(cnt > maxcnt && k >= 2){
			puts("�����������ƣ��������룬��Ϸʧ��!!!");
			printf("��ȷ���� %d \n", num); 
			system("pause");
			return; 
		}
		printf("���������Guess:"); 
		fflush(stdin); int ret = scanf("%d", &x); fflush(stdin);
		++cnt;
		if(ret == 0) {
			puts("���Ϸ�������");
			continue; 
		}
		if(x > num) printf("̫����\n");
		else if(x < num) printf("̫С��\n");
		else{
			puts("Congratulations! ��¶�����!"); end = clock(); double dur=(double)(end-start)/CLK_TCK;
			int this_pts = pts[k] - Min((int)dur * 2, 495) - Min(50 * (cnt-1), 495);
			Data[id].data[1][2+k] = Max(Data[id].data[1][2+k], this_pts);
			printf("��ǰΪ�� %d ���ӹؿ������ε÷� %d  ��ʱ��%.3lfs ��ߵ÷� %d\n", k, this_pts, dur, Data[id].data[1][2+k]);
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
			pritnf("���ϴ�ͨ����ǰ %d ���ӹؿ������Ŀǰ�÷�Ϊ %d\n", LastLevel, LastPoints); 
			printf("�����㽲����� %d ���ӹؿ���ף����ˣ�\n", LastLevel + 1);
			entrance = LastLevel + 1;
		} else
		puts("�㻹û�й���Ϸ��¼�����ϴ�����AC�����潫Ϊ�㿪��һ������Ϸ\n"); 
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
	//puts("����һ���Ĵ������ƣ�����Խ�ٸ���"); 
    //if(Data[id].data[1][1]) printf("���ϴε���Ѽ�¼��%d��\n", Data[id].data[1][1]);
	int op = -1; Data[id].data[1][0] = 5;
	if(lg[2] == 0)
		for(int i = 2; i <= 666666; ++i) lg[i] = lg[i>>1] + 1; 
	while(1){
		system("cls"); 
    	puts("��ӭ��������С��Ϸ, ����Ϸ����3���ӹؿ�, ͨ����1�����ɽ�����һ����Ϸ:");
		printf("LRL52�������һ��������Χ��������������������������LRL52�ᷴ����������������Դ�С\n");
		printf("1.��ʼ��Ϸ\n2.��ʷ��¼\n3.�˳���Ϸ\n");
		printf("���������ѡ��:");  op = -1;
		fflush(stdin); scanf("%d", &op); fflush(stdin);
		if(op == 1){
			printf("�����߼�¼��ͨ����ǰ %d ���ӹؿ����������ѡ��1 - %d�е������ӹؿ�\n", Level, Min(3, Level+1));
			printf("���������ѡ��:"); op = -1; fflush(stdin); scanf("%d", &op); fflush(stdin); 
			if(op < 1 || op > Min(3, Level+1)){puts("���Ϸ�����������"); system("pause");}
			else Game(op); 
		}
		else if(op == 2){
			/*system("cls"); printf("��ǰ�û�: %s\n", Data[id].username); 
			printf("\t\t\t\t  ������Ϸ[�ؿ�1]�ܷ�   �ӹؿ�1   �ӹؿ�2   �ӹؿ�3  \n");
			printf("\t\t\t\t  %18d   %7d   %7d   %7d   \n", MaxPoints, Data[id].data[1][3], Data[id].data[1][4], Data[id].data[1][5]);
			system("pause");*/
			system("cls"); printf("��ǰ�ؿ���������Ϸ[�ؿ�1]   ��ǰ�û�: %s\n\n", Data[id].username);  
			printf("\t\t\t\t     Username   ����   �ܷ�   �ӹؿ�1   �ӹؿ�2   �ӹؿ�3  \n");
			ShowRank(1);
			system("pause");
		} 
		else if(op == 3) return;
		else {puts("���Ϸ�����������"); system("pause");}
	}
}
