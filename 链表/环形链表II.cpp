/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(!head){
            return NULL;
        }
        ListNode *p=head;
        ListNode *q=head;
        while(true){
            p=p->next;
            q=q->next;
            if(!q){
                return NULL;
            }
            q=q->next;
            if(!q){
                return NULL;
            }
            if(p==q){
                break;
            }
        }
        p=head;
        while(p!=q){
            p=p->next;
            q=q->next;
        }
        return p;
    }
};

 */