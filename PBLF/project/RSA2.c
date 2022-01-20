#include "RSA.h"
#define int long long
static int e = 3049, d = 2361049, p = 194591273;
#define N 1055 
static const int base = 1e4;
static const int power = 4;
struct Big{
	int a[N], len;
	Big(){memset(a, 0, sizeof a); len = 1;}
	void init_s(const char *s){
		int L = strlen(s); memset(a, 0, sizeof a);
		len = (L + power - 1) / power;
		for(int t = 0, w = 1, i = 0; i < L; ++i, w *= 10){
			if(i % power == 0) w = 1, ++t;
			a[t] += w * (s[i] - '0');
		}
	}
	void init_int(int x){
		int L = 0;
		do{
			s[L++] = x % 10 + '0';
			x /= 10;
		}while(x);
		s[L] = '\0'; init_s(s);
	}
	void print(){
		printf("%d", a[len]);
		for(int i = len - 1; i >= 1; --i) printf("%0*d", power, a[i]);
	}
}

int ksm(int a, int b){
	int ret = 1;
	while(b){
		if(b & 1) ret = 1LL * ret * a % p;
		a = 1LL * a * a % p;
		b >>= 1; 
	}	
	return ret;
}

int Encode(int x){return ksm(x, e);}
int Decode(int x){return ksm(x, d);}
#undef int
