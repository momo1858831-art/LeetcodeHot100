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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int addcount=0,sum;
        ListNode *head=new ListNode();
        ListNode *p=head;
        while(l1&&l2){
            sum=l1->val+l2->val+addcount;
            addcount=sum/10;
            sum%=10;
            ListNode *tmp=new ListNode(sum);
            p->next=tmp;
            p=tmp;
            l1=l1->next;
            l2=l2->next;
        }
        while(l1){
            sum=addcount+l1->val;
            addcount=sum/10;
            sum%=10;
            ListNode *tmp=new ListNode(sum);
            p->next=tmp;
            p=tmp;
            l1=l1->next;
        }
        while(l2){
            sum=addcount+l2->val;
            addcount=sum/10;
            sum%=10;
            ListNode *tmp=new ListNode(sum);
            p->next=tmp;
            p=tmp;
            l2=l2->next;
        }
        if(addcount){
            ListNode *tmp=new ListNode(addcount);
            p->next=tmp;
            p=tmp;
        }
        return head->next;
    }
};