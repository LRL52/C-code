#include <stdio.h>
#include <Windows.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>

void CursorJump(int x, int y)
{
	COORD pos; //������λ�õĽṹ�����
	pos.X = x; //����������
	pos.Y = y; //����������
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE); //��ȡ����̨���
	SetConsoleCursorPosition(handle, pos); //���ù��λ��
}

int main(){
	printf("1");
	CursorJump(3, 3);
	printf("1");
	printf("%lld\n", LONG_LONG_MAX); 
	return 0;
}
