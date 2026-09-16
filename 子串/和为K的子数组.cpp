#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int count=0,sum=0;
        unordered_map<int,int>hash;
        hash[0]++;
        for(int i=0;i<nums.size();i++){  
            sum+=nums[i];
            if(hash.find(sum-k)!=hash.end()){
                count+=hash[sum-k];
            }
            hash[sum]++;
        }
        return count;
    }
};