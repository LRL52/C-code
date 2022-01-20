#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char s[105][25], *Min = s[0], *Max = s[0];
int cnt = 0;

void Chkmin(char *b){
	int n = strlen(Min) < strlen(b) ? strlen(Min) : strlen(b);
	for(int i = 0; i < n; ++i){
		if(Min[i] != b[i]){
			if(b[i] < Min[i]) Min = b;
			return;
		}
	}
	if(strlen(b) < strlen(Min)) Min = b;
}

void Chkmax(char *b){
	int n = strlen(Max) < strlen(b) ? strlen(Max) : strlen(b);
	for(int i = 0; i < n; ++i){
		if(Max[i] != b[i]){
			if(b[i] > Max[i]) Max = b;
			return;
		}
	}
	if(strlen(b) > strlen(Min)) Max = b;
}

int main(){
	while(1){
		scanf("%s", s[cnt++]);
		int len = strlen(s[cnt-1]);
		if(len == 4) break;
	}
	//char *Min = s[0], *Max = s[0];
	for(int i = 1; i < cnt; ++i){
		Chkmin(s[i]);
		Chkmax(s[i]);
	}
	printf("Smallest word: %s\n", Min);
	printf("Largest word: %s", Max);
}
