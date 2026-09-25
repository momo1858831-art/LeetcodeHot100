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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(!list1&&!list2){
            return NULL;
        }
        ListNode *head=new ListNode();
        ListNode *p=head;
        while(list1&&list2){
            int x;
            if(list1->val<list2->val){
                x=list1->val;
                list1=list1->next;
            }
            else{
                x=list2->val;
                list2=list2->next;
            }
            ListNode *tmp=new ListNode(x);
            p->next=tmp;
            p=tmp;
        }
        p->next=list1?list1:list2;
        return head->next;
    }
};