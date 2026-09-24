struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(!head){
            return nullptr;
        }
        if(!head->next){
            return head;
        }
        ListNode *p1=head;
        ListNode *p2=p1->next;
        ListNode *tmp;
        p1->next=nullptr;
        while(p2){
            tmp=p2->next;
            p2->next=p1;
            p1=p2;
            p2=tmp;
        }
        head=p1;
        return head;
    }
};