#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>


int main(){
    FILE *fp;
    fp = fopen("./data.txt", "r");
    if(fp == NULL){
        printf("Error\n");
        return 0;
    }
    int n = -1;
    if(fscanf(fp, "%d", &n) == EOF)
        printf("New User\n");
    else
        printf("%d\n", n);
    srand((unsigned)time(NULL));
    long long x = (long long)rand() * rand() % 10000;
    printf("x = %lld\n", x);
    fp = fopen("./data.txt", "w");
    fprintf(fp, "%lld\n", x);
    fclose(fp);
    printf("%d\n", strcmp("1", "1"));
    return 0;
}