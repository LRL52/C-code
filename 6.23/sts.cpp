//ID: LRL52  Date: 2021.6.23
#define rep(i, a, b) for(int i = (a); i <= (b); ++i) 
#include<bits/stdc++.h>
using namespace std;
const int N = 1055, M = 2055; char ss[1 << 21], *A = ss, *B = ss, cc;
inline char gc(){return A == B && (B = (A = ss) + fread(ss, 1, 1 << 21, stdin), A == B) ? EOF : *A++;}
template<class T>inline void rd(T &x){
	int f = 1; x = 0 , cc = gc(); while(cc < '0' || cc > '9'){if(cc == '-') f = -1; cc = gc(); }
	while(cc >= '0' && cc <= '9'){x = x * 10 + (cc ^ 48); cc = gc();} x *= f;
}

int main(){
	freopen("read.in", "r", stdin);
	//freopen("read.out", "w", stdout);
	int x;
	rep(i, 1, 5){
		rd(x);
		printf("%d\n", x);
	}
	return 0; 
}
