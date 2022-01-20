/*
 * ??? :???(2021090906016)
 * ????:2021-09-16, Thu, 15:44:29
 * ????:100
 */


#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
char s[12][12];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

int main(){
	for(int i = 1; i <= 10; ++i)
	    for(int j = 1; j <= 10; ++j)
	        s[i][j] = '.';
	int x = 1, y = 1, step = 1; s[1][1] = 'A';
	//srand(time(NULL));
	while(1){
		if(++step > 26) break; int ok = 0;
		for(int i = 0; i < 4; ++i){
			int t = rand()%4;
			int nx = x + dx[t];
			int ny = y + dy[t];
			if(nx < 1 || nx > 10 || ny < 1 || ny > 10) continue;
			if(s[nx][ny] != '.') continue;
			x = nx, y = ny, ok = 1;
			s[nx][ny] = 'A' + step - 1;
			break;
		}
		if(ok == 0) break;
	}
	for(int i = 1; i <= 10; ++i){
		for(int j = 1; j <= 10; ++j)
		    putchar(s[i][j]);
		putchar('\n');
	}
}
