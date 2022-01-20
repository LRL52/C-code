#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
#include<stdio.h>

int main(int argc, char *argv[]){
    freopen("read.in", "r", stdin);
    int x;
    /*rep(i, 1, 5){
        rd(x);
        printf("%d\n", x);
    }*/
    printf("argv[0] = %s\n", argv[0]);
    for(int i = 0; i < argc; ++i){
        printf("%s\n", argv[i]);
    }
    return 0;
}