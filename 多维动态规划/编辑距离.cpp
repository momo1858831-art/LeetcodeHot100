#include<iostream>
using namespace std;

class Solution {
public:
    int min(int a,int b,int c){
        a=a<b?a:b;
        a=a<c?a:c;
        return a;
    }
    int minDistance(string word1, string word2) {
        int m=word1.length(),n=word2.length();
        vector<int>dp(n+1);
        for(int i=0;i<=n;i++){
            dp[i]=i;
        }
        int pre,old;
        for(int i=1;i<=m;i++){
            pre=dp[0];
            dp[0]=i;
            for(int j=1;j<=n;j++){
                old=dp[j];
                if(word1[i-1]==word2[j-1]){
                    dp[j]=pre;
                }
                else{
                    dp[j]=min(pre,old,dp[j-1])+1;
                }
                pre=old;
            }
        }
        return dp[n];
    }
};