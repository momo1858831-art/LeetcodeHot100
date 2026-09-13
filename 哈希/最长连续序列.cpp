#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>s;
        unordered_set<int>start;
        int ans=0;
        for(int i=0;i<nums.size();i++){
            s.insert(nums[i]);
        }
        for(int i=0;i<nums.size();i++){
            if(s.find(nums[i]-1)!=s.end()){
                continue;
            }
            if(start.find(nums[i])!=start.end()){
                continue;
            }
            int tmp=nums[i]+1;
            while(1){
                if(s.find(tmp)!=s.end()){
                    tmp++;
                    continue;
                }
                ans=max(ans,tmp-nums[i]);
                start.insert(nums[i]);
                break;
            }
        }
        return ans;
    }
};