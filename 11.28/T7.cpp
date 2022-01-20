//ID: LRL52  Date: 2021.11.28
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
#include<bits/stdc++.h>
using namespace std;

int check(int a, int b, int c){
	int a2 = a*a, b2 = b*b, c2 = c*c;
	if(a2 + b2 == c2) return 1;
	if(a2 + c2 == b2) return 1;
	if(b2 + c2 == a2) return 1;
	return 0;
}

int main(){
	int a, b, c;
	scanf("%d%d%d", &a, &b, &c);
	if(check(a, b, c)) puts("YES");
	else puts("NO");
	return 0;
}
