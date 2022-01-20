//ID: LRL52  Date: 2021.11.28
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
#include<bits/stdc++.h>
using namespace std;
const int N = 100055, M = 2055; char ss[1 << 21], *A = ss, *B = ss, cc;
inline char gc(){return A == B && (B = (A = ss) + fread(ss, 1, 1 << 21, stdin), A == B) ? EOF : *A++;}
template<class T>inline void rd(T &x){
	int f = 1; x = 0, cc = gc(); while(cc < '0' || cc > '9'){if(cc == '-') f = -1; cc = gc();}
	while(cc >= '0' && cc <= '9'){x = x * 10 + (cc ^ 48); cc = gc();} x *= f;
}
int n;
int a[N], fa[N];

int find(int x){return fa[x] == x ? x : fa[x] = find(fa[x]);}

int main(){
	//freopen("read.in", "r", stdin);
	rd(n);
	rep(i, 1, n) rd(a[i]), fa[i] = i;
	int ans = n;
	rep(i, 1, n){
		int f1 = find(i), f2 = find(a[i]);
		if(f1 != f2){
			fa[f2] = f1;
			--ans;
		}
	}
	printf("%d\n", ans);
	return 0;
}
