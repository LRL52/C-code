//ID: LRL52  Date: 2021.6.23
#define rep(i, a, b) for(int i = (a); i <= (b); ++i) 
#include<bits/stdc++.h>
#include<windows.h>
using namespace std;
const int N = 1055, M = 2055; char ss[1 << 21], *A = ss, *B = ss, cc;
inline char gc(){return A == B && (B = (A = ss) + fread(ss, 1, 1 << 21, stdin), A == B) ? EOF : *A++;}
template<class T>inline void rd(T &x){
	int f = 1; x = 0 , cc = gc(); while(cc < '0' || cc > '9'){if(cc == '-') f = -1; cc = gc(); }
	while(cc >= '0' && cc <= '9'){x = x * 10 + (cc ^ 48); cc = gc();} x *= f;
}

int main(){
	while(true){
		time_t tm = time(0);
		char* dt = ctime(&tm);
		int h = (*(dt + 11) - '0') * 10 + (*(dt + 12) - '0');
		if(h >= 21){
			system("start http://cx.sceea.cn/");
			SetCursorPos(654, 394);
			Sleep(1000);
			mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
			Sleep(10);
			mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
			return 0;
		}
	}
	return 0; 
}
