//ID: LRL52  Date: 2021.11.27
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
#include<bits/stdc++.h>
using namespace std;
const int N = 1055, M = 2055; char ss[1 << 21], *A = ss, *B = ss, cc;
inline char gc(){return A == B && (B = (A = ss) + fread(ss, 1, 1 << 21, stdin), A == B) ? EOF : *A++;}
template<class T>inline void rd(T &x){
	int f = 1; x = 0, cc = gc(); while(cc < '0' || cc > '9'){if(cc == '-') f = -1; cc = gc();}
	while(cc >= '0' && cc <= '9'){x = x * 10 + (cc ^ 48); cc = gc();} x *= f;
}
int n;
int Cnt[N];

int Solve(int x){
	while(x){
		int y = x % 10;
		x /= 10;
		if(Cnt[y]) --Cnt[y];
		else return 0;
	}
	return 1;
}

int main(){
	//("read.in", "r", stdin);
	cin >> n;
	rep(i, 0, 9) Cnt[i] = n;
	int ans = 0;
	while(Solve(ans+1)) ++ans;
	printf("%d\n", ans);
	return 0;
}
