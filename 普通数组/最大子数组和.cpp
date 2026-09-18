#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.size()==1){
            return nums[0];
        }
        // 以位置i结尾的最大子数组和
        int dp[nums.size()];
        dp[0]=nums[0];
        for(int i=1;i<nums.size();i++){
            if(dp[i-1]>0){
                dp[i]=dp[i-1]+nums[i];
            }
            else{
                dp[i]=nums[i];
            }
        }
        int res=dp[0];
        for(int i=1;i<nums.size();i++){
            res=max(res,dp[i]);
        }
        return res;
    }
};