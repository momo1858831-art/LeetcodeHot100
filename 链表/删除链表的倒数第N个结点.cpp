#include<iostream>
using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head){
            return NULL;
        }
        ListNode *p=head,*q=head,*r;
        for(int i=0;i<n;i++){
            p=p->next;
        }
        while(p){
            r=q;
            p=p->next;
            q=q->next;
        }
        if(q==head){
            head=head->next;
            return head;
        }
        r->next=q->next;
        return head;
    }
};
