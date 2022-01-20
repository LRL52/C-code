#include "Subtask3.h" //�������ͷ�ļ�
#include "diynode.h"  //�����Զ���ṹ������,
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<windows.h>
extern node Data[]; //������Ϸ����Data 
extern int id, taskid; //����id, taskid, idΪ��ǰ�û���Ӧ���������, ����Data[]�±�, taskid��ʾ��ǰ���ڽ��л򼴽�����Ĺؿ�, ��ܿ��ܻ��õ� 
//�����������д��������������ȵ�
#define MaxPoints Data[id].data[3][1]
#define Level Data[id].data[3][2]
static int a[100+5];
static int N[] = {0, 3, 5, 7};
static int M[] = {0, 3, 25, 125};
static int pts[] = {0, 1000, 2500, 6666};
typedef struct ListNode{
    int x, y;
    struct ListNode *prev;
}ListNode;
static ListNode *head, *tail;

static void print(int n){
    printf("���е�%d��ʯ����������Ϊ��\n", n);
    for(int i = 1; i <= n; ++i) printf("%d ", a[i]);
    putchar('\n'); putchar('\n');
}

static int checkend(int n){
    for(int i = 1; i <= n; ++i) if(a[i] > 0) return 0;
    return 1;
}

static void Insert(int x, int y){
    ListNode *cur = (ListNode*)malloc(sizeof(ListNode));
    cur->x = x, cur->y = y;
    cur->prev = tail, tail = cur;
}

static void Delete(){
    if(tail == head){
        printf("���Ϸ��Ĳ���������\n\n");
        return;
    }
    static ListNode *p;
    a[tail->x] += tail->y, p = tail, tail = tail->prev, free(p);
    a[tail->x] += tail->y, p = tail, tail = tail->prev, free(p);
    puts("���سɹ�"); Sleep(2000);
}

static void NimGame(int k){
    printf("\n-------------------��ʼ����Ϸ---------------------\n"); 
    Sleep(1000); head = (ListNode*)malloc(sizeof(ListNode)), tail = head;
    if(k <= 2) printf("��ǰΪ�� %d ���ӹؿ�: ���� %d ��ʯ�ӣ�ÿ��ʯ�ӵĸ��������� %d ��\n", k, N[k], M[k]); 
	else printf("��ǰΪ�� %d ��(BOSS)�ӹؿ�: ���� %d ��ʯ�ӣ�ÿ��ʯ�ӵĸ��������� %d �����������3�γ��ػ���\n", k, N[k], M[k]);
	printf("��ÿ�������ÿո�ָ���2����x y\n��ʾ����x��ʯ������y��\n����-1��ʾ������һ�����LRL52�Ĳ���������-2��ʾ�˳�������Ϸ\n\n");
    srand((unsigned)time(NULL)); int x = 0, y = 0, n = N[k], m = M[k], cnt = 0;
    for(int i = 1; i <= n - 1; ++i) a[i] = rand() * rand() % m + 1, x ^= a[i];
    if(k == 1){
    	for(int i = 1; i <= m; ++i) if(x ^ i) {x ^= i; break;}
    	a[n] = x;
	} else{
		if(x > 0 && rand() % 5) a[n] = x;
    	else a[n] = rand() * rand() % m + 1;
	}
	clock_t start = clock(), end;
    while(1){
        print(n);
        if(checkend(n)){
            puts("You loss the game! ! !");
            system("pause"); return;
        }
        while(1){
            printf("��������Ĳ���x y:");
            fflush(stdin); x = 0; scanf("%d", &x);
            if(x == -1){
            	if(k == 3 && cnt == 3){
            		puts("���ش����Ѵ����ޣ�������Ч��"); 
            		continue; 
				}
                Delete(); print(n);  fflush(stdin); ++cnt;
                continue;
            }
            if(x == -2){fflush(stdin); return;}
            scanf("%d", &y); fflush(stdin);
            if(x > n || x < 1 || y <= 0 || a[x] < y){
                puts("���Ϸ��Ĳ���������");
                continue;
            }
            a[x] -= y;
            Insert(x, y);
            break;
        }
        print(n);
        if(checkend(n)){
            puts("Congratulations, You win!");
            end = clock(); double dur=(double)(end-start)/CLK_TCK;
			int this_pts = pts[k] - Min((int)dur * 2, 495) - Min(50 * cnt, 495);
			Data[id].data[3][2+k] = Max(Data[id].data[3][2+k], this_pts);
			printf("��ǰΪ�� %d ���ӹؿ������ε÷� %d  ��ʱ��%.3lfs ���ش�����%d  ��ߵ÷� %d\n", k, this_pts, dur, cnt, Data[id].data[3][2+k]);
 			MaxPoints = Max(MaxPoints, Data[id].data[3][3] + Data[id].data[3][4] + Data[id].data[3][5]);
			Level = Max(Level, k);
			Data[id].taskid = Data[id].taskid > 3 ? Data[id].taskid : 3; system("pause");
            return;
        }
        Sleep(2000); x = 0;
        for(int i = 1; i <= n; ++i) x ^= a[i];
        if(x){
            for(int i = 1; i <= n; ++i)
                if((a[i] ^ x) < a[i]){
                    y = a[i] - (a[i]^x);
                    printf("LRL52��������%d��ʯ������%d��\n", i, y);
                    a[i] -= y; Insert(i, y);
                    break;
                }
        } else{
            for(int i = 1; i <= n; ++i)
                if(a[i] > 0){
                    y = rand() * rand() % a[i] + 1;
                    printf("LRL52��������%d��ʯ������%d��\n", i, y);
                    a[i] -= y; Insert(i, y);
                    break;
                }
        }
    }
}

void Subtask3(){ //���潫�������Ϸ���, ȷ��return��taskid����Ϊ���ʵ�ֵ, 1~Gamecnt��ʾ��Ӧ�ؿ�, -1��ʾ�˳���Ϸ
    Data[id].data[3][0] = 5;
    int op = -1; Sleep(1000); 
	while(1){
		system("cls");
		printf("�q===================�����==================�r\n");
		printf("��  �� �ӭ����Subtask3: LRL52�Ĳ��ġ� ��    ��\n");
		printf("�t=======�����==============================�s\n");
	    printf("��Ϸ�����������ɶѸ���������ʯ��\n");
	    printf("���LRL52ÿ�οɴ�����һ��ʯ����ȡ�������öʯ���ӵ�������ȡ�꣬���ܲ�ȡ����ӵ�����������ʸ�\n");
    	printf("ÿ��ֻ�ܴ�һ����ȡ�����ûʯ�ӿ�ȡ��һ��������\n");
		printf("1.��ʼ��Ϸ\n2.��ʷ��¼\n3.�˳���Ϸ\n");
		printf("���������ѡ��:"); 
		fflush(stdin); scanf("%d", &op); fflush(stdin);
		if(op == 1){
			printf("�����߼�¼��ͨ����ǰ %d ���ӹؿ����������ѡ��1 - %d�е������ӹؿ�\n", Level, Min(3, Level+1));
			printf("���������ѡ��:"); op = -1; scanf("%d", &op); fflush(stdin); 
			if(op < 1 || op > Min(3, Level+1)) {puts("���Ϸ�����������"); system("pause");}
			else NimGame(op); 
		}
		else if(op == 2){
			system("cls"); printf("��ǰ�ؿ���LRL52�Ĳ���[�ؿ�2]   ��ǰ�û�: %s\n\n", Data[id].username);  
			printf("\t\t\t\t     Username   ����   �ܷ�   �ӹؿ�1   �ӹؿ�2   �ӹؿ�3  \n");
			ShowRank(3);
			//printf("\t\t\t\t  %22d   %7d   %7d   %7d   \n", MaxPoints, Data[id].data[3][3], Data[id].data[3][4], Data[id].data[3][5]);
			system("pause");
		} 
		else if(op == 3) return;
		else { puts("���Ϸ�����������"); system("pause"); } 
	}
}
