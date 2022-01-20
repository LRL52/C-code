#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int val;
    struct node *next, *prev;
}Node;

void Insert_L(Node *head, Node **addr, int *NodeCnt, int x){
    Node *cur = (Node*)malloc(sizeof(Node));
    cur->val = x;
    cur->next = head->next;
    cur->prev = head;
    head->next->prev = cur;
    head->next = cur;
    addr[++(*NodeCnt)] = cur;
}

void Insert_R(Node *tail, Node **addr, int *NodeCnt, int x){
    Node *cur = (Node*)malloc(sizeof(Node));
    cur->val = x;
    cur->prev = tail->prev;
    cur->next = tail;
    tail->prev->next = cur;
    tail->prev = cur;
    addr[++(*NodeCnt)] = cur;
}

void Delete_k(Node **addr, int k){
    Node *cur = addr[k];
    cur->prev->next = cur->next;
    cur->next->prev = cur->prev;
    free(cur);
}

void Insert_kL(Node **addr, int k, int *NodeCnt, int x){
    Node *kth = addr[k], *cur = (Node*)malloc(sizeof(Node));
    cur->val = x;
    kth->prev->next = cur;
    cur->prev = kth->prev;
    cur->next = kth;
    kth->prev = cur;
    addr[++(*NodeCnt)] = cur;
}

void Insert_kR(Node **addr, int k, int *NodeCnt, int x){
    Node *kth = addr[k], *cur = (Node*)malloc(sizeof(Node));
    cur->val = x;
    kth->next->prev = cur;
    cur->next = kth->next;
    cur->prev = kth;
    kth->next = cur;
    addr[++(*NodeCnt)] = cur;
}

int main(){
    freopen("read.in", "r", stdin);
    int q, k, x; char op;
    scanf("%d\n", &q);
    Node *head = (Node*)malloc(sizeof(Node));
    Node *tail = (Node*)malloc(sizeof(Node)); 
    head->next = tail, tail->prev = head;
    int NodeCnt = 0;
    Node **addr = (Node**)malloc(q * sizeof(Node*));
    for(int i = 1; i <= q; ++i){
        scanf("%c", &op);
        if(op == 'L'){
            scanf("%d\n", &x);
            Insert_L(head, addr, &NodeCnt, x);
        } else 
        if(op == 'R'){
            scanf("%d\n", &x);
            Insert_R(tail, addr, &NodeCnt, x);
        } else
        if(op == 'D'){
            scanf("%d\n", &k);
            Delete_k(addr, k);
        } else
        if(op == 'I'){
            scanf("%c%d%d\n", &op, &k, &x);
            if(op == 'L') Insert_kL(addr, k, &NodeCnt, x);
            else Insert_kR(addr, k, &NodeCnt, x); 
        }
    }
    for(Node *p = head->next; p != tail; p = p->next)
        printf("%d ", p->val);
    return 0;
}