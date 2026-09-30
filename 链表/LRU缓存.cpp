#include<iostream>
#include<unordered_map>
using namespace std;

struct Node{
    int key;
    int value;
    struct Node *next,*prev;
};

class LRUCache {
public:

    int c;
    struct Node *head=new Node();
    unordered_map<int,Node*>hash;

    void add(Node *p){
        p->next=head->next;
        head->next->prev=p;
        p->prev=head;
        head->next=p;
    }

    void remove(Node *p){
        p->prev->next=p->next;
        p->next->prev=p->prev;
    }

    LRUCache(int capacity) {
        c=capacity;
        head->next=head;
        head->prev=head;
    }
    
    int get(int key) {
        if(hash.find(key)!=hash.end()){
            remove(hash[key]);
            add(hash[key]);
            return hash[key]->value;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(hash.find(key)!=hash.end()){
            remove(hash[key]);
            add(hash[key]);
            hash[key]->value=value;
            return;
        }
        if(c>0){
            c--;
        }
        else{
            hash.erase(head->prev->key);
            remove(head->prev);
        }
        Node *p=new Node();
        p->key=key;
        p->value=value;
        add(p);
        hash[key]=p;
    }
};