#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int i=0,n=nums.size(),j;
        while(i<nums.size()){
            if(nums[i]==i+1){
                i++;
                continue;
            }
            if(nums[i]<=0||nums[i]>n){
                i++;
                continue;
            }
            if(nums[nums[i]-1]!=nums[i]){
                swap(nums[nums[i]-1],nums[i]);
            }
            else{
                i++;
            }
        }
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=i+1){
                return i+1;
            }
        }
        return n+1;
    }
};