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
    ListNode* mergeSort(ListNode *head,ListNode *tail){
        if(head==tail){
            return head;
        }
        if(head->next==tail){
            if(head->val>tail->val){
                swap(head->val,tail->val);
            }
            return head;
        }
        ListNode *p=head,*q=head->next;
        while(1){
            p=p->next;
            q=q->next;
            if(q==tail){
                break;
            }
            q=q->next;
            if(q==tail){
                break;
            }
        }
        ListNode *l=p->next;
        p->next=NULL;
        ListNode *left=mergeSort(head,p);
        ListNode *right=mergeSort(l,tail);
        ListNode ll;
        ListNode *h=&ll;
        while(left&&right){
            if(left->val<right->val){
                h->next=left;
                h=left;
                left=left->next;
            }
            else{
                h->next=right;
                h=right;
                right=right->next;
            }
        }
        if(left){
            h->next=left;
        }
        else{
            h->next=right;
        }
        return ll.next;
    }
    ListNode* sortList(ListNode* head) {
        if(!head){
            return NULL;
        }
        ListNode *p=head;
        while(p->next){
            p=p->next;
        }
        head=mergeSort(head,p);
        return head;
    }
};