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
    ListNode* swapPairs(ListNode* head) {
        if(!head){
            return NULL;
        }
        if(head&&!head->next){
            return head;
        }
        ListNode *h=new ListNode();
        h->next=head;
        ListNode *p=head,*q=head->next,*r,*t,*pre=h;
        while(true){
            r=p->next;
            t=q->next;
            p->next=t;
            q->next=p;
            pre->next=q;
            pre=p;
            p=t;
            if(!p){
                break;
            }
            q=t->next;
            if(!q){
                break;
            }
        }
        return h->next;
    }
};