#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int>res(nums.size(),1);
        int lp=1,rp=1;
        int left=0,right=nums.size()-1;
        while(left<=nums.size()-1&&right>=0){
            res[left]*=lp;
            res[right]*=rp;
            lp*=nums[left++];
            rp*=nums[right--];
        }
        return res;
    }
};