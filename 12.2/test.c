#include<stdio.h>
#include "lrl52.h"

int main(int argc, char *argv[]){
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i) scanf("%d", &a[i]);
    printf("%d\n", findmax(n));
    return 0;
}