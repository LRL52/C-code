#include<stdio.h>
#include "max.h"

int main(){
	int a = 5, b = 6;
	for(int i = 0; i < 8; i++)
		printf("%d\n", Max(a, i));
	printf("%d\n", Max(a, b));
	return 0;
}