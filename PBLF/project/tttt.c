#include<stdio.h>
#include<stdlib.h>
#define int long long
static const int e = 3049, d = 2361049, p = 194591273;

int ksm(int a, int b){
	int ret = 1;
	while(b){
		if(b & 1) ret = 1LL * ret * a % p;
		a = 1LL * a * a % p;
		b >>= 1; 
	}	
	return ret;
}
#undef int

int main(){
	printf("%lld\n", LONG_LONG_MAX);
	printf("%lld\n", ksm(123, e));
	return 0;
} 
