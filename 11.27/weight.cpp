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
const int maxn = 1e5;
int n;
int a[N], f[2][maxn+55];

int main(){
	freopen("read.in", "r", stdin);
	rd(n);
	rep(i, 1, n) rd(a[i]);
	sort(a + 1, a + n + 1, greater<int>()); 
	f[0][0] = 1;
	rep(i, 1, n){
		int now = i & 1, lst = now ^ 1;
		rep(j, 0, maxn){
			f[now][j] |= f[lst][j];
			if(j - a[i] >= 0) f[now][j] |= f[lst][j - a[i]];
			if(j + a[i] <= maxn) f[now][j] |= f[lst][j + a[i]];
		}
	} 
	int ans = 0;
	rep(i, 1, maxn) ans += f[n&1][i];
	printf("%d\n", ans);
	return 0;
}
