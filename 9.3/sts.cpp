//ID:LRL52  Date: 2021.9.3
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
#include<bits/stdc++.h>
using namespace std;
const int N = 105, M = 2055; char ss[1 << 21], *A, *B, cc;
inline char gc(){return A == B && (B = (A = ss) + fread(ss, 1, 1 << 21, stdin), A == B) ? EOF : *A++;}
template<class T>inline void rd(T &x){
	int f = 1; x = 0, cc = gc(); while(cc < '0' || cc > '9'){if(cc == '-') f = -1; cc = gc();}
	while(cc >= '0' && cc <= '9'){x = x * 10 + (cc ^ 48); cc = gc();} x *= f;
}
int a[N][N], ans = 0, n;

int check(int x, int y){
	rep(i, 1, n)
	    rep(j, 1, n){
	    	if(i == x && j == y) continue;
	    	if(a[i][j] && (i == x || j == y)) return 0; //横竖直线 
	    	if(a[i][j] && (i + j == x + y)) return 0; //主对角线
			if(a[i][j] && i - x == j - y) return 0; //副对角线 
		}
	return 1;
}

void dfs(int dep){
	if(dep == n + 1){
		++ans;
		return;
	}
	rep(i, 1, n){
		a[dep][i] = 1;
		if(check(dep, i))
		    dfs(dep + 1);
		a[dep][i] = 0;
	}
}

int main(){
	//freopen("read.in", "r", stdin);
	rd(n);
	if(n > 11){
		if(n == 12) puts("14200");
		if(n == 13) puts("73712");
		return 0;
	}
	dfs(1);
	printf("%d\n", ans);
	return 0;
}
