#include<stdio.h>

void func(int a[][13]){
    for(int i = 0; i < 13; ++i){
        for(int j = 0; j < 13; ++j)
            printf("%d ", a[i][j]);
        putchar('\n');
    }
}

int main(){
    int chess[13][13] = {1};
    /*for(int i = 0; i < 13; ++i){
        for(int j = 0; j < 13; ++j)
            printf("%d ", chess[i][j]);
        putchar('\n');
    }*/
    func(chess);
    return 0;
}
