#include<iostream>
using namespace std;

class MinStack {
public:
    int min_v;
    stack<int>s1,s2;
    MinStack() {

    }
    
    void push(int value) {
        if(s1.empty()){
            min_v=value;
        }
        s1.push(value);
        min_v=min(min_v,value);
        s2.push(min_v);
    }
    
    void pop() {
        s1.pop();
        s2.pop();
        if(!s2.empty())
            min_v=s2.top();
    }
    
    int top() {
        return s1.top();
    }
    
    int getMin() {
        return s2.top();
    }
};