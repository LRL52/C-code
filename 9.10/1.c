/*
 * ����ˡ���������(2021090906016)
 * ���ʱ�䣺2021-09-10, Fri, 10:00:48
 * ϵͳ���֣�28
 */


//ID: LRL52  Date: 2021.9.10
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
#include<stdio.h>
/*const int N = 1055, M = 2055; char ss[1 << 21], *A = ss, *B = ss, cc;
inline char gc(){return A == B && (B = (A = ss) + fread(ss, 1, 1 << 21, stdin), A == B) ? EOF : *A++;}
template<class T>inline void rd(T &x){
	int f = 1; x = 0, cc = gc(); while(cc < '0' || cc > '9'){if(cc == '-') f = -1; cc = gc();}
	while(cc >= '0' && cc <= '9'){x = x*10 + (cc^48); cc = gc();} x *= f;
}*/

int main(){
	//freopen("read.in", "r", stdin);
	float loan, rate, dx;
	scanf("%f%f%f", &loan, &rate, &dx);
	const float t = rate / 100.0 / 12.0;
	loan = loan - dx + loan * t;
	printf("Balance remaining after first payment: $%.2f\n", loan);
	loan = loan - dx + loan * t;
    printf("Balance remaining after second payment: $%.2f\n", loan);
    loan = loan - dx + loan * t;
    printf("Balance remaining after third payment: $%.2f", loan);
	return 0;
}
