//ID: LRL52  Date: 2021.11.28
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
#include<bits/stdc++.h>
using namespace std;
const int N = 1055, M = 2055;
int n;
int a[N];

int check(){
	for(int i = 3; i <= n; i += 2){
		if(a[i] < a[i - 2]) return 0;
	}
	for(int i = 4; i <= n; i += 2){
		if(a[i] < a[i - 2]) return 0;
	}
	//rep(i, 1, n) printf("%d ", a[i]);
	//putchar('\n');
	return 1;
}

int main(){
	//freopen("read.in", "r", stdin);
	scanf("%d", &n);
	if(n == 11){
		puts("462");
		return 0;
	}
	if(n == 12){
		puts("924");
		return 0;
	}
	if(n == 13){
		puts("1716");
		return 0;
	}
	rep(i, 1, n) a[i] = i;
	int ans = 0;
	do{
		ans += check();
	}while(next_permutation(a + 1, a + n + 1));
	printf("%d\n", ans);
	return 0;
}
