#include<iostream>
using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        if(s.size()==0){
            return 0;
        }
        int n=s.length();
        vector<int>dp(n,0);
        int res=0;
        for(int i=1;i<n;i++){
            if(s[i]=='('){
                continue;
            }
            if(s[i-1]=='('){
                dp[i]=(i>=2?dp[i-2]:0)+2;
            }
            else if((i-dp[i-1]-1)>=0){
               if(s[i-dp[i-1]-1]=='('){
                    dp[i]=((i-dp[i-1]-2)>=0?dp[i-dp[i-1]-2]:0)+dp[i-1]+2;
                } 
            }
            res=max(res,dp[i]);
        }
        return res;
    }
};