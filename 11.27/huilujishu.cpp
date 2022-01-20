//ID: LRL52  Date: 2021.11.27
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
#include<bits/stdc++.h>
using namespace std;
const int N = (1<<21)+5 , M = 2055; char ss[1 << 21], *A = ss, *B = ss, cc;
inline char gc(){return A == B && (B = (A = ss) + fread(ss, 1, 1 << 21, stdin), A == B) ? EOF : *A++;}
template<class T>inline void rd(T &x){
	int f = 1; x = 0, cc = gc(); while(cc < '0' || cc > '9'){if(cc == '-') f = -1; cc = gc();}
	while(cc >= '0' && cc <= '9'){x = x * 10 + (cc ^ 48); cc = gc();} x *= f;
}
#define int long long
int n;
int f[N][22], G[22][22];

int gcd(int a, int b){return a == 0 ? b : gcd(b%a, a);}

#undef int
int main(){
#define int long long
	//freopen("read.in", "r", stdin);
	n = 21;
	for(int i = 0; i < n; ++i)
		for(int j = 0; j < n; ++j){
			if(gcd(i+1, j+1) == 1)
				G[i][j] = 1;
		} 
	f[1][0] = 1;
	for(int i = 1; i < (1<<n); ++i){
		for(int k = 0; k < n; ++k){
			if(f[i][k] == 0) continue;
			if(((i>>k)&1) == 0) continue;
			for(int j = 0; j < n; ++j){
				if((i>>j)&1) continue;
				if(G[k][j] == 0) continue;
				f[i|(1<<j)][j] += f[i][k];
			}
		} 
	}
	int ans = 0;
	for(int i = 1; i < n; ++i)
		if(G[i][0])
			ans += f[(1<<n)-1][i];
	printf("%lld\n", ans);  
	return 0;
}
