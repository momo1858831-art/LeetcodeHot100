#include<iostream>
#include<queue>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

struct Compare{
    bool operator()(ListNode *p,ListNode *q){
        return p->val>q->val;
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0){
            return NULL;
        }
        if(lists.size()==1){
            return lists[0];
        }
        priority_queue<ListNode*,vector<ListNode*>,Compare>q;
        for(size_t i=0;i<lists.size();i++){
            if(!lists[i]){
                continue;
            }
            q.push(lists[i]);
        }
        ListNode *head=new ListNode(),*p;
        ListNode *h=head;
        while(!q.empty()){
            p=q.top();
            head->next=p;
            q.pop();
            if(p->next){
                q.push(p->next);
            }
            head=head->next;
        }
        head->next=NULL;
        ListNode *res=h->next;
        return res;
    }
};