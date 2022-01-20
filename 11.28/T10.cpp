//ID: LRL52  Date: 2021.11.28
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
#include<bits/stdc++.h>
using namespace std;
const int N = 305;
const int inf = 0x3f3f3f3f;
const int dx[] = {-1, 0, 0, 1};
const int dy[] = {0, -1, 1, 0};
int n, m;
int instk[N][N], f[N][N], vis[N][N], a[N][N];
char s[N][N];

int F(int i, int j){
	if(instk[i][j]) return inf;
	if(vis[i][j]) return f[i][j];
	instk[i][j] = 1;
	for(int k = 0; k < 4; ++k){
		int nx = i + dx[k];
		int ny = j + dy[k];
		if(nx < 1 || nx > n || ny < 1 || ny > m) continue;
		if(a[i][j] && a[nx][ny] == 0)
			f[i][j] = min(f[i][j], F(nx, ny) + 1);
		else if(a[i][j] == 0)
			f[i][j] = min(f[i][j], F(nx, ny));
	}
	vis[i][j] = 1, instk[i][j] = 0;
	return f[i][j];
}

int main(){
	//freopen("read.in", "r", stdin);
	scanf("%d%d", &n, &m); 
	rep(i, 1, n) scanf("%s", s[i] + 1);
	rep(i, 1, n)
		rep(j, 1, m)
			a[i][j] = s[i][j] - '0' - 1;
	memset(f, 0x3f, sizeof f);
	if(a[1][1]) f[1][1] = 1;
	else f[1][1] = 0;
	vis[1][1] = 1;
	F(n, m);
	if(f[n][m] == inf) printf("-1");
	else printf("%d", f[n][m]);
	return 0;
}
