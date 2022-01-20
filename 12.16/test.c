#include<stdio.h>
#include<string.h>

int main(){
	char password[100] = {0};
	printf("Please input the password:");
	int i = 0;
	while (1) { 
		char c = getch();
		if (c == '\r') { //输入回车就退出循环
			break;
		}
		if (c == '\b') { //delete键
			if (i > 0) {
				password[i - 1] = '\0';
				i--;
				printf("\b");	//输出\b，让光标回退一格
				printf(" \b");  //输出空格覆盖掉要删除的字符，然后输出\b再把光标回退。
			}
			continue;
		}
		password[i++] = c;
		printf("*");
	}
	putchar('\n');
	puts(password); 
	return 0;
} 
