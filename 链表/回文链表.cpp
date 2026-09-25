/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if(head&&!head->next){
            return true;
        }
        ListNode *p=head;
        int count=0;
        while(p){
            count++;
            p=p->next;
        }
        int flag=0;
        if(count%2!=0){
            flag=1;
        }
        //cout<<flag<<endl;
        count/=2;
        int now=0;
        p=head;
        ListNode* q;
        ListNode *tmp;
        q=p->next;
        p->next=NULL;
        while(now<count-1){
            tmp=q->next;
            q->next=p;
            p=q;
            q=tmp;
            now++;
        }
        if(flag){
            q=q->next;
        }
        while(p&&q){
            if(p->val!=q->val){
                return false;
            }
            p=p->next;
            q=q->next;
        }
        return true;
    }
};

*/