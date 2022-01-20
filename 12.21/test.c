#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char s[] = "123 3 -2 34 6233";
char wr[1005];

int main(){
	/*char *p = s; int len = strlen(s), x; 
	while(p - s < len){
		p += sscanf(p, "%d", &x);
		printf("%d\n", x); 
	} */
	char *p = wr;
	for(int i = 1; i <= 10; ++i)
		p += sprintf(p, "%d\n", i);
	puts(wr);
	return 0;
}
