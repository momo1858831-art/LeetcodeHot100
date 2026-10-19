#include<iostream>
using namespace std;

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        if(n==1){
            return false;
        }
        int sum=0,max=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            if(max<nums[i]){
                max=nums[i];
            }
        }
        if(sum%2){
            return false;
        }
        int target=sum>>1;
        if(max>target){
            return false;
        }
        vector<bool>dp(target+1,0);
        dp[0]=true;
        for(int i=0;i<n;i++){
            for(int j=target;j>=nums[i];j--){
                if(dp[j-nums[i]]){
                    dp[j]=true;
                }
            }
        }
        return dp[target];
    }
};