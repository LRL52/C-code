#include "Subtask2.h" //引入你的头文件
#include "diynode.h"  //引入自定义结构体类型,
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
extern node Data[]; //共享游戏数据Data 
extern int id, taskid; //共享id, taskid, id为当前用户对应的数字序号, 用作Data[]下标, taskid表示当前正在进行或即将进入的关卡, 你很可能会用到 
//你可以在下面写函数，定义变量等等
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

void Subtask2(){ //下面将是你的游戏入口, 确保return后将taskid更改为合适的值, 1~Gamecnt表示对应关卡, -1表示退出游戏
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
            Data[id].taskid = Data[id].taskid > 2 ? Data[id].taskid : 2; //更新用户的最高关卡记录
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
	Switchtask(); //切换关卡, 可在退出时调用
}
