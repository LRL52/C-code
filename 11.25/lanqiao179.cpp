#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 55;
int n, D, K;
vector<int> a[N];

int main(){
	freopen("read.in", "r", stdin);
	ios::sync_with_stdio(0);
	cin >> n >> D >> K;
	int ts, id;
	rep(i, 1, n){
		cin >> ts >> id;
		a[id].push_back(ts);
	}
	rep(i, 0, 100000)
		if(a[i].size() > 0)
			sort(a[i].begin(), a[i].end());
	rep(i, 0, 100000){
		for(unsigned int j = 0, k = -1; j < a[i].size(); ++j){
			while(k + 1 < a[i].size() && a[i][k+1] - a[i][j] + 1 <= D) ++k;
			if((int)k - (int)j + 1 >= K){
				printf("%d\n", i);
				break;
			}
		}
	}
	return 0;
}
