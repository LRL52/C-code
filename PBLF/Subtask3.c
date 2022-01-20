#include "Subtask3.h" //�������ͷ�ļ�
#include "diynode.h"  //�����Զ���ṹ������,
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<windows.h>
extern node Data[]; //������Ϸ����Data 
extern int id, taskid; //����id, taskid, idΪ��ǰ�û���Ӧ���������, ����Data[]�±�, taskid��ʾ��ǰ���ڽ��л򼴽�����Ĺؿ�, ��ܿ��ܻ��õ� 
//�����������д��������������ȵ�
#define n 5
#define m 25
int a[n+5];
typedef struct ListNode{
    int x, y;
    struct ListNode *prev;
}ListNode;
ListNode *head, *tail;

void print(){
    printf("���е�%d��ʯ����������Ϊ��\n", n);
    for(int i = 1; i <= n; ++i) printf("%d ", a[i]);
    putchar('\n'); putchar('\n');
}

int checkend(){
    for(int i = 1; i <= n; ++i) if(a[i] > 0) return 0;
    return 1;
}

void Insert(int x, int y){
    ListNode *cur = (ListNode*)malloc(sizeof(ListNode));
    cur->x = x, cur->y = y;
    cur->prev = tail, tail = cur;
}

void Delete(){
    if(tail == head){
        printf("���Ϸ��Ĳ���������\n\n");
        return;
    }
    static ListNode *p;
    a[tail->x] += tail->y, p = tail, tail = tail->prev, free(p);
    a[tail->x] += tail->y, p = tail, tail = tail->prev, free(p);
    puts("���سɹ�"); Sleep(2000);
    print();
}

void NimGame(){
    printf("\n-------------------��ʼ����Ϸ---------------------\n");
    Sleep(1000); head = (ListNode*)malloc(sizeof(ListNode)), tail = head;
    printf("��ÿ�������ÿո�ָ���2����x y\n��ʾ����x��ʯ������y��\n����-1��ʾ������һ�����LRL52�Ĳ���\n\n");
    srand((unsigned)time(NULL)); int x = 0, y = 0;
    for(int i = 1; i <= n - 1; ++i) a[i] = rand() * rand() % m + 1, x ^= a[i];
    if(x > 0 && rand() % 5) a[n] = x;
    else a[n] = rand() * rand() % m + 1;
    while(1){
        print();
        if(checkend()){
            puts("You loss the game! ! !");
            return;
        }
        while(1){
            printf("��������Ĳ���x y:");
            scanf("%d", &x);
            if(x == -1){
                Delete(); fflush(stdin);
                continue;
            }
            scanf("%d", &y); fflush(stdin);
            if(x > n || x < 1 || y <= 0 || a[x] < y){
                puts("���Ϸ��Ĳ���������");
                continue;
            }
            a[x] -= y;
            Insert(x, y);
            break;
        }
        print();
        if(checkend()){
            puts("Congratulations, You win!");
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
    system("cls"); Sleep(1000);
    printf("�q===================�����==================�r\n");
	printf("��  �� �ӭ����Subtask3: LRL52�Ĳ��ġ� ��    ��\n");
	printf("�t=======�����==============================�s\n");
    printf("��Ϸ��������%d��ʯ�ӣ�ÿһ��ʯ�ӵĸ���������%d��\n", n, m);
    printf("���LRL52ÿ�οɴ�����һ��ʯ����ȡ�������öʯ���ӵ�������ȡ�꣬���ܲ�ȡ\n");
    printf("ÿ��ֻ�ܴ�һ����ȡ�����ûʯ�ӿ�ȡ��һ��������\n");
    int op;
	while(1){
		printf("1.��ʼ��Ϸ\n2.�л��ؿ�\n3.�˳���Ϸ\n");
		printf("���������ѡ��:"); 
		scanf("%d", &op);
		if(op == 1) NimGame();
		else if(op == 2){
			Switchtask();
			return;
		}else{
			taskid = -1;
			return;
		}
	}
	Switchtask(); //�л��ؿ�, �����˳�ʱ����
}
