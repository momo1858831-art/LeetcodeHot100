#include<iostream>
using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        vector<int>arr(20001,0);
        for(int i=0;i<nums.size();i++){
            arr[nums[i]+10000]++;
        }
        int ans;
        for(int i=20000;i>=0;i--){
            k-=arr[i];
            if(k<=0){
                ans=i-10000;
                break;
            }
        }
        return ans;
    }
};