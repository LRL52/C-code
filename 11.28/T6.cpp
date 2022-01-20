//ID: LRL52  Date: 2021.11.28
#include<bits/stdc++.h>
using namespace std;


int main(){
	int p, t;
	scanf("%d%d", &p, &t);
	int cnt = 0;
	if(t % 12 == 0) cnt = t / 12;
	else cnt = t / 12 + 1;
	printf("%d", cnt * p);
	return 0;
}
