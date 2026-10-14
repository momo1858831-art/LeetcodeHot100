#include<iostream>
using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        int dp[n+1];
        int m=1;
        for(int i=1;i<=n;i++){
            dp[i]=1;
            for(int j=1;j<=i;j++){
                if(nums[j-1]<nums[i-1]){
                    dp[i]=max(dp[i],dp[j]+1);
                }
            }
            if(m<dp[i]){
                m=dp[i];
            }
        }
        return m;
    }
};