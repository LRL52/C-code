#include<bits/stdc++.h>
using namespace std;
char s[105];

int main(){
	//freopen("read.in", "r", stdin);
	freopen("read.out", "w", stdout);
	int T; scanf("%d", &T);
	while(T--){
		int n;
		scanf("%d%s", &n, s + 1);
		int ans = 0;
		for(int i = 1; i <= n; ++i){
			ans += s[i] - '0';
			//ans += s[i] - '0' > 0; 
			if(i != n && s[i] - '0') ++ans;
		}
		printf("%d\n", ans);
	}
	return 0;
} 
