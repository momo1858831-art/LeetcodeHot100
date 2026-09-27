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
    void reverse(ListNode *head,ListNode *tail){
        if(head==tail){
            return;
        }
        ListNode *p=head,*q=head->next,*tmp;
        while(q!=tail){
            tmp=q->next;
            q->next=p;
            p=q;
            q=tmp;
        }
        tail->next=p;
        head->next=NULL;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *p=head;
        int count=0;
        while(p){
            count++;
            p=p->next;
        }
        count/=k;
        p=head;
        ListNode *q;
        ListNode *r;
        ListNode *h=new ListNode();
        ListNode *hh=h;
        while(count--){
            q=p;
            for(int i=0;i<k-1;i++){
                q=q->next;
            }
            r=q->next;
            reverse(p,q);
            h->next=q;
            h=p;
            p=r;
        }
        h->next=r;
        return hh->next;
    }
};