#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int cur;
        vector<vector<int>>res;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            if(nums[i]>0){
                break;
            }
            if(i&&nums[i]==nums[i-1]){
                continue;
            }
            int target=0-nums[i];
            int j=i+1,k=nums.size()-1;
            while(j<k){
                if(nums[j]+nums[k]==target){
                    vector<int>tmp(3);
                    tmp[0]=nums[i];
                    tmp[1]=nums[j];
                    tmp[2]=nums[k];
                    res.push_back(tmp);
                    cur=j++;
                    while((j<k)&&(nums[j]==nums[cur])){
                       j++; 
                    }
                    cur=k--;
                    while((j<k)&&(nums[cur]==nums[k])){
                       k--;
                    }
                }
                else if(nums[j]+nums[k]>target){
                    cur=k--;
                    while((j<k)&&(nums[cur]==nums[k])){
                       k--;
                    }
                }
                else{
                    cur=j++;
                    while((j<k)&&(nums[j]==nums[cur])){
                       j++; 
                    }
                }
            }
        }
        return res;
    }
};