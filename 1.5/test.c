#include<stdio.h>
#include<string.h>

int main(){
    char s1[25], s2[25];
    scanf("%s", s1);
    int i, p = 0, cnt = 0;
    for(i = 0; i < strlen(s1); i++){
        s2[p++] = s1[i];
        if(++cnt == 2) s2[p++] = '*', cnt = 0; 
    }
    s2[p] = 0;
    puts(s2);
    return 0;
}