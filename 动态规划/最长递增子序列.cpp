#include<iostream>
using namespace std;

class Solution {
public:
    void insert(int x,vector<int>& dp,int n){
        int left=1,right=n;
        int mid;
        while(left<=right){
            mid=(left+right)/2;
            if(dp[mid]>x){
                right=mid-1;
            }
            else if(dp[mid]<x){
                left=mid+1;
            }
            else{
                return;
            }
        }
        dp[left]=x;
    }
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n+1);
        dp[1]=nums[0];
        int len=1;
        for(int i=2;i<=n;i++){
            if(nums[i-1]>dp[len]){
                dp[++len]=nums[i-1];
                continue;
            }
            if(nums[i-1]==dp[len]){
                continue;
            }
            insert(nums[i-1],dp,len);
        }
        return len;
    }
};