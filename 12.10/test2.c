#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int val;
    struct node *next;
}Node;
Node a;

void fun(Node *p){
    Node *cur = (Node*)malloc(sizeof(Node));
    cur->val = 10;
    p = cur;
}

int main(){
    Node *p = &a;
    p->val = 5;
    printf("%d\n", p->val);
    fun(p);
    printf("%d\n", p->val);
    return 0;
}