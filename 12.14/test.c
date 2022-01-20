#include<stdio.h>
struct node{
    int val;
    struct node *next;
};

int main(){
    struct node *p = NULL, *q;
    p->next = q;
    return 0;
}