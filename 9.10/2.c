//ID: LRL52  Date: 2021.9.10
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
#include<stdio.h>
/*const int N = 1055, M = 2055; char ss[1 << 21], *A = ss, *B = ss, cc;
inline char gc(){return A == B && (B = (A = ss) + fread(ss, 1, 1 << 21, stdin), A == B) ? EOF : *A++;}
template<class T>inline void rd(T &x){
	int f = 1; x = 0, cc = gc(); while(cc < '0' || cc > '9'){if(cc == '-') f = -1; cc = gc();}
	while(cc >= '0' && cc <= '9'){x = x*10 + (cc^48); cc = gc();} x *= f;
}*/
const char txt[2][3] = {"AM", "PM"};//突然不懂改成txt[2][2]有啥毛病 

int main(){
	//freopen("read.in", "r", stdin);
	int h, m, flag = 0;
	scanf("%d:%d", &h, &m);
	if(h > 0 && h < 12) flag = 0;
	else if(h == 24 || h == 0){
		h = 12, flag = 0;
	} else{
		flag = 1;
		if(h != 12) h %= 12;
	}
	printf("Equivalent 12-hour time: %d:%02d %s", h, m, txt[flag]);
	//printf("%s", txt[flag]);
	return 0;
}
