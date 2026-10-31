#include<iostream>
#include<stack>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<int>sk;
        char c;
        for(int i=0;i<s.length();i++){
            if(s[i]=='('||s[i]=='['||s[i]=='{'){
                sk.push(s[i]);
                continue;
            }
            if(sk.empty()){
                return false;
            }
            c=sk.top();
            if(c=='('){
                if(s[i]!=')'){
                    return false;
                }
            }
            if(c=='['){
                if(s[i]!=']'){
                    return false;
                }
            }
            if(c=='{'){
                if(s[i]!='}'){
                    return false;
                }
            }
            sk.pop();
        }
        return sk.empty();
    }
};