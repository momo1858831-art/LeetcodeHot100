struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};
 
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int cnt1=0,cnt2=0;
        ListNode *tmp=headA;
        while(tmp){
            cnt1++;
            tmp=tmp->next;
        }
        tmp=headB;
        while(tmp){
            cnt2++;
            tmp=tmp->next;
        }
        ListNode *tmp1=headA;
        ListNode *tmp2=headB;
        while(cnt1>cnt2){
            tmp1=tmp1->next;
            cnt1--;
        }
        while(cnt2>cnt1){
            tmp2=tmp2->next;
            cnt2--;
        }
        if(tmp1==tmp2){
            return tmp1;
        }
        while(tmp1&&tmp2){
            if(tmp1->next==tmp2->next){
                return tmp1->next;
            }
            tmp1=tmp1->next;
            tmp2=tmp2->next;
        }
        return nullptr;
    }
};