#include<iostream>
using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n=s.length();
        vector<bool>dp(n+1,false);
        dp[0]=true;
        string str;
        for(int i=0;i<n;i++){
            if(!dp[i]){
                continue;
            }
            for(auto word:wordDict){
                if(word==s.substr(i,word.length())){
                    dp[i+word.length()]=true;
                }
            }
        }
        return dp[n];
    }
};