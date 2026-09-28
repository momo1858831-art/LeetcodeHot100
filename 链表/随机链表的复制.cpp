#include<iostream>
#include<unordered_map>
using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* random;
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head){
            return NULL;
        }
        Node *p=head;
        while(p){
            Node *tmp=new Node(p->val);
            tmp->next=p->next;
            p->next=tmp;
            p=tmp->next;
        }
        p=head;
        while(p){
            if(p->random){
                p->next->random=p->random->next;
            }
            else{
                p->next->random=NULL;
            }
            p=p->next->next;
        }
        p=head;
        Node *h=p->next;
        Node *hh=h;
        while(p){
            p->next=h->next;
            p=p->next;
            if(!p){
                break;
            }
            h->next=p->next;
            h=h->next;
        }
        return hh;
    }
};