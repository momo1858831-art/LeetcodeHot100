#include<iostream>
using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1,-1);
        dp[0]=0;
        for(int i=1;i<=amount;i++){
            for(int j=0;j<coins.size();j++){
                if(coins[j]>i){
                    continue;
                }
                if(dp[i-coins[j]]==-1){
                    continue;
                }
                if(dp[i]==-1){
                    dp[i]=1+dp[i-coins[j]];
                    continue;
                }
                dp[i]=min(dp[i],1+dp[i-coins[j]]);
            }
        }
        return dp[amount];
    }
};