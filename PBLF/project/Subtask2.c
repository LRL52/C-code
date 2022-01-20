#include "Subtask2.h" //引入你的头文件
#include "diynode.h"  //引入自定义结构体类型,
#include<stdio.h>
extern node Data[]; //共享游戏数据Data 
extern int id, taskid; //共享id, taskid, id为当前用户对应的数字序号, 用作Data[]下标, taskid表示当前正在进行或即将进入的关卡, 你很可能会用到 
//你可以在下面写函数，定义变量等等

void Subtask2(){ //下面将是你的游戏入口, 确保return后将taskid更改为合适的值, 1~Gamecnt表示对应关卡, -1表示退出游戏
    puts("Subtask2:"); //这只是一个演示测试而已, 建议删除
    Data[id].taskid = Data[id].taskid > 2 ? Data[id].taskid : 2; //更新用户的最高关卡记录
	Switchtask(); //切换关卡, 可在退出时调用
}
