//ID: LRL52  Date: 2021.9.24
#include<bits/stdc++.h>
#define int long long
int i_i, P, N;

struct comp{
	int x, y;
	comp(int _x = 0, int _y = 0){
		x = _x, y = _y;
	}
};

inline comp operator*(const comp&t1, const comp&t2){
	comp ret;
	ret.x = (1LL*t1.x*t2.x%P + 1LL*t1.y*t2.y%P*i_i%P)%P;
	ret.y = (1LL*t1.x*t2.y%P + 1LL*t2.x*t1.y%P)%P;
	return ret;
}

comp ksm(comp a, int b){
	comp ret = comp(1, 0);
	while(b){
		if(b & 1) ret = ret * a;
		a = a * a;
		b >>= 1;
	}
	return ret;
}

int qp(int a, int b){
	int ret = 1;
	while(b){
		if(b & 1) ret = 1LL * ret * a % P;
		a = 1LL * a * a % P;
		b >>= 1;
	}
	return ret;
}

int is_residue(int x){
	return qp(x, (P-1)>>1) == 1;
}

void Solve(){
	if(N == 0){puts("0");return;}
	if(!is_residue(N)){puts("Hola!");return;}
	int a = 1LL * rand() * rand() % P;
	i_i = (1LL * a * a % P - N + P) % P; 
	while(is_residue(i_i)){
		a = 1LL * rand() * rand() % P;
		i_i = (1LL * a * a % P - N + P) % P; 
	}
	comp ans = ksm(comp(a, 1), (P+1)>>1);
	int ans1 = ans.x, ans2 = -ans1 + P;
	if(ans1 == ans2){
		printf("%lld\n", ans1);
		return;
	}
	if(ans1 > ans2) std::swap(ans1, ans2);
	printf("%lld %lld\n", ans1, ans2);
}

#undef int
int main(){
#define int long long
	int T; scanf("%lld", &T);
	while(T--){
		scanf("%lld%lld", &N, &P); N %= P;
		Solve();
	}
	return 0;
}
