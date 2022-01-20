//ID: LRL52  Date: 2021.11.27
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 55, M = 2e6 + 55; char ss[1 << 21], *A = ss, *B = ss, cc;
inline char gc(){return A == B && (B = (A = ss) + fread(ss, 1, 1 << 21, stdin), A == B) ? EOF : *A++;}
template<class T>inline void rd(T &x){
	int f = 1; x = 0, cc = gc(); while(cc < '0' || cc > '9'){if(cc == '-') f = -1; cc = gc();}
	while(cc >= '0' && cc <= '9'){x = x * 10 + (cc ^ 48); cc = gc();} x *= f;
}
int n;
int a[N], nxt[M], vis[M];

int find(int x){return nxt[x] == x ? x : nxt[x] = find(nxt[x]);}

int main(){
	freopen("read.in", "r", stdin);
	rd(n);
	rep(i, 1, n) rd(a[i]);
	rep(i, 1, 1555555) nxt[i] = i;
	rep(i, 1, n){
		int x = a[i];
		if(vis[x]) x = find(x);
		vis[x] = 1;
		nxt[x] = x + 1;
		printf("%d ", x);
	}
	return 0;
}
