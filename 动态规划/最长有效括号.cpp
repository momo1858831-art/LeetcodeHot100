#include<iostream>
using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        if(s.size()==0){
            return 0;
        }
        int n=s.length();
        stack<int>st;
        int res=0;
        vector<int>v(n,0);
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                st.push(i);
            }
            else{
                if(!st.empty()){
                    v[i]=v[st.top()]=1;
                    st.pop();
                }
            }
        }
        int i=0,j;
        while(i<n){
            while(i<n&&!v[i]){
              i++;  
            }
            if(i==n){
                break;
            }
            j=i;
            i++;
            while(i<n&&v[i]){
                i++;
            }
            i--;
            if(res<i-j+1){
                res=i-j+1;
            }
            i++;
        }
        return res;
    }
};