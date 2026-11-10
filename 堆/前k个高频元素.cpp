#include<iostream>
using namespace std;
class Solution {
public:
    struct compare{
        bool operator()(pair<int,int>a,pair<int,int>b){
            return a.second>b.second;
        }
    };
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>count;
        for(int i=0;i<nums.size();i++){
            count[nums[i]]++;
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,compare>p;
        int i=0;
        for(auto c:count){
            if(i<k){
                p.push({c.first,c.second});
                i++;
                continue;
            }
            if(p.top().second<c.second){
                p.pop();
                p.push({c.first,c.second});
            }
        }
        vector<int>ans;
        while(!p.empty()){
            ans.push_back(p.top().first);
            p.pop();
        }
        return ans;
    }
};