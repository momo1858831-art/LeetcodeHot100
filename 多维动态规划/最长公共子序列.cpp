#include<iostream>
using namespace std;

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m=text1.length(),n=text2.length();
        int pre,old;
        vector<int>dp(n+1,0);
        for(int i=1;i<=m;i++){
            pre=dp[0];
            for(int j=1;j<=n;j++){  
                old=dp[j];
                if(text1[i-1]==text2[j-1]){
                    dp[j]=pre+1;
                }
                else{
                    dp[j]=max(old,dp[j-1]);
                }
                pre=old;
            }
        }
        return dp[n];
    }
};