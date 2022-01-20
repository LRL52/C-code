#include "Subtask2.h" //�������ͷ�ļ�
#include "diynode.h"  //�����Զ���ṹ������,
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
extern node Data[]; //������Ϸ����Data 
extern int id, taskid; //����id, taskid, idΪ��ǰ�û���Ӧ���������, ����Data[]�±�, taskid��ʾ��ǰ���ڽ��л򼴽�����Ĺؿ�, ��ܿ��ܻ��õ� 
//�����������д��������������ȵ�
static int pcinput;
static int userinput;
static int input;
#define echo ">_ "
static char case_win(int left, int right); //Which player win;The left is user,the right is computer.
static int echoinput(int inputnum);        //Operations performed based on the output of two global variables.

static char case_win(int left, int right)
{
    char reslut;
    /*
 * declare
 * fist->1
 * scissor->2
 * cloth->3
 */
    /*
 * rule:
 * fist->scissor
 * scissor->cloth
 * cloth->fist
 */
    /*judge,the left is the player*/
    if (left == right)
    {
        reslut = 'P';
    }
    else
    {
        if (left == 1)
        {
            if (right == 2)
            {
                reslut = 'L';
            }
            else if (right == 3)
            {
                reslut = 'R';
            }
        }
        else if (left == 2)
        {
            if (right == 1)
            {
                reslut = 'R';
            }
            else if (right == 3)
            {
                reslut = 'L';
            }
        }
        else if (left == 3)
        {
            if (right == 1)
            {
                reslut = 'L';
            }
            else if (right == 2)
            {
                reslut = 'R';
            }
        }
    }
    return reslut;
}
static int echoinput(int inputnum)
{
    int reslut = 0;
    switch (inputnum)
    {
    case 1:
        printf("(fist)");
        break;
    case 2:
        printf("(scissor)");
        break;
    case 3:
        printf("(cloth)");
        break;
    default:
        printf("(error)");
        reslut = 1;
        break;
    }
    return reslut;
}

void Subtask2(){ //���潫�������Ϸ���, ȷ��return��taskid����Ϊ���ʵ�ֵ, 1~Gamecnt��ʾ��Ӧ�ؿ�, -1��ʾ�˳���Ϸ
    printf("Welcome to the guessing game.");
    Sleep(2500);
    printf("\n");
    printf("You will start a guessing game with the computer.");
    Sleep(2500);
    printf("\n");
    printf("You can check the feel of today's game here.");
    Sleep(2500);
    printf("\n\n");
    printf("rule\n\n");
    puts("1.fist\n");
    puts("2.scissor\n");
    puts("3.cloth\n");
    printf("%s yourput:", echo);
    scanf("%d", &userinput);
    printf("\n");
    if (echoinput(userinput) == 1)
    {
        Sleep(1000);
        system("cls");
        main();
    }
    else
    {
        printf("\n");
        printf("\n");
        printf("%s wait for the computer.\0", echo);
        Sleep(500);
        printf(".");
        Sleep(500);
        printf(".\n");
        srand((unsigned)time(NULL));
        pcinput = rand() % 3 + 1;
        printf("\n");
        echoinput(pcinput);
        printf("\n");
        printf("\n");
        if (case_win(userinput, pcinput) == 'L')
        {
            printf("You win.Good luck in the next game.");
            Data[id].taskid = Data[id].taskid > 2 ? Data[id].taskid : 2; //�����û�����߹ؿ���¼
        }
        else if (case_win(userinput, pcinput) == 'R')
        {
            printf("You lose.This will be your worst luck in the whole game.");
        }
        else
        {
            printf("Draw.Your mind will be as agile as computers");
        }
        printf("\n");
        printf("\n");
        printf("--------------------");
        printf("\n");
        printf("Play again?Input 1 or 2,1 is yes,2 is no.\n");
        scanf("%d", &input);
        if (input == 1)
        {
            printf("\n");
            printf("\n");
            printf("three...");
            Sleep(1000);
            printf("two...");
            Sleep(1000);
            printf("one...");
            Sleep(1000);
            system("cls");
            main();
        }
        else
            printf("\n");
        printf("The following games are interesting and brain-burning.Have a good time.");
        return;
    }
    return;
	Switchtask(); //�л��ؿ�, �����˳�ʱ����
}