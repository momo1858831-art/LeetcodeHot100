#include<iostream>
using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,greater<int>>p;
        for(int i=0;i<nums.size();i++){
            if(i<k){
                p.push(nums[i]);
                continue;
            }
            if(nums[i]>p.top()){
                p.pop();
                p.push(nums[i]);
            }
        }
        return p.top();
    }
};