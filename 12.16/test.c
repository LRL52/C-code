#include<stdio.h>
#include<string.h>

int main(){
	char password[100] = {0};
	printf("Please input the password:");
	int i = 0;
	while (1) { 
		char c = getch();
		if (c == '\r') { //����س����˳�ѭ��
			break;
		}
		if (c == '\b') { //delete��
			if (i > 0) {
				password[i - 1] = '\0';
				i--;
				printf("\b");	//���\b���ù�����һ��
				printf(" \b");  //����ո񸲸ǵ�Ҫɾ�����ַ���Ȼ�����\b�ٰѹ����ˡ�
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
