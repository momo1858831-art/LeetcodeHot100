/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };

class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(!head){
            return false;
        }
        ListNode *p=head,*q=head;
        while(true){
            p=p->next;
            q=q->next;
            if(!q){
                return false;
            }
            q=q->next;
            if(!q){
                return false;
            }
            if(p==q){
                return true;
            }
        }
    }
};

 */