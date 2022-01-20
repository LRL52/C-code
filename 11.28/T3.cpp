//ID: LRL52  Date: 2021.11.28
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
#include<bits/stdc++.h>
using namespace std;
const int N = 1055, M = 2055; char ss[1 << 21], *A = ss, *B = ss, cc;
inline char gc(){return A == B && (B = (A = ss) + fread(ss, 1, 1 << 21, stdin), A == B) ? EOF : *A++;}
template<class T>inline void rd(T &x){
	int f = 1; x = 0, cc = gc(); while(cc < '0' || cc > '9'){if(cc == '-') f = -1; cc = gc();}
	while(cc >= '0' && cc <= '9'){x = x * 10 + (cc ^ 48); cc = gc();} x *= f;
}
int n = 2021;

int solve(int x){
	for(int i = 1; i * i <= x; ++i){
		if(x % i ==0){
			int d1 = i, d2 = x / i;
			if((d1 + d2) % 2 == 0) return 1;
		}
	}
	return 0;
}

int main(){
	//freopen("read.in", "r", stdin);
	int ans = 0;
	rep(i, 1, 2021) 
		ans += solve(i);
	printf("%d\n", ans);
	//cout << solve(2018) << endl;
	return 0;
}
