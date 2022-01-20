#include <stdio.h>
#include <Windows.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>

void CursorJump(int x, int y)
{
	COORD pos; //定义光标位置的结构体变量
	pos.X = x; //横坐标设置
	pos.Y = y; //纵坐标设置
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE); //获取控制台句柄
	SetConsoleCursorPosition(handle, pos); //设置光标位置
}

int main(){
	printf("1");
	CursorJump(3, 3);
	printf("1");
	printf("%lld\n", LONG_LONG_MAX); 
	return 0;
}
