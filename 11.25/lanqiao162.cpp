#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
#include<bits/stdc++.h>
using namespace std;
const int N = 1055;
int n, tot, ct;
int fa[N];
double X[N], Y[N], Z[N];
struct edge{
	int u, v;
	double w;
}e[N * N];
struct cmp{
	inline bool operator()(const edge&t1, const edge&t2)const{
		return t1.w < t2.w;
	}
};

inline double sq(double x){return x * x;}
int find(int x){return fa[x] == x ? x : fa[x] = find(fa[x]);}

int main(){
	//freopen("read.in", "r", stdin);
	ios::sync_with_stdio(0);
	cin >> n;
	rep(i, 1, n) cin >> X[i] >> Y[i] >> Z[i];
	rep(i, 1, n){
		rep(j, i+1, n){
			e[++ct].u = i, e[ct].v = j;
			//e[ct].w = sqrt(sq(X[i] - X[j]) + 
			//			   sq(Y[i] - Y[j]) +
			//			   sq(Z[i] - Z[j]));
			e[ct].w = sqrt(sq(X[i] - X[j]) + sq(Y[i] - Y[j])) + sq(Z[i] - Z[j]);
		}
	}
	sort(e + 1, e + ct + 1, cmp());
	rep(i, 1, n) fa[i] = i;
	double ans = 0.0;
	rep(i, 1, ct){
		int u = e[i].u, v = e[i].v;
		int f1 = find(u), f2 = find(v);
		if(f1 != f2){
			fa[f2] = f1;
			ans += e[i].w;
			if(++tot == n - 1) break;
		}
	}
	printf("%.2lf\n", ans);
	return 0;
} 
