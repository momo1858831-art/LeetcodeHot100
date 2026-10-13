#include<iostream>
using namespace std;

class Solution {
public:
    bool find(string s,vector<string>& wordDict){
        for(int i=0;i<wordDict.size();i++){
            if(s==wordDict[i]){
                return true;
            }
        }
        return false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        int n=s.length();
        vector<bool>dp(n+1,false);
        dp[0]=true;
        string str;
        for(int i=0;i<n;i++){
            for(int j=i+2;j<=n;j++){
                str=s.substr(i+1,j);
                if(dp[i]&&find(str,wordDict)){
                    dp[j]=true;
                }
            }
        }
        return dp[n];
    }
};