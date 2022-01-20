#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define bool int


struct ListNode {
    int val;
    struct ListNode *next;
};

bool hasCycle(struct ListNode *head) {
    if(head == NULL || head->next == NULL) return false;
    struct ListNode *p1 = head, *p2 = head->next;
    while(p1 != NULL && p2 != NULL){
        if(p1 == p2) return true;
        p1 = p1->next;
        p2 = p2->next;
        if(p2 != NULL) p2 = p2->next;
    }
    return false;
}