#include "RSA.h"
#define int long long
static int e = 3049, d = 2361049, p = 194591273;

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