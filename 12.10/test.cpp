#include<cstdio>
void fun(int &x, int &y){
    x = 6, y = 7;
}

int main(){
    int x = 1, y = 2;
    printf("%d %d\n", x, y);
    fun(x, y);
    printf("%d %d\n", x, y);
    return 0;
}