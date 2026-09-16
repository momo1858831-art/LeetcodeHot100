#include<iostream>
#include<vector>
#include<queue>
using namespace std;
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<pair<int,int>,vector<pair<int,int>>>queue;
        for(int i=0;i<k;i++){
            queue.push({nums[i],i});
        }
        vector<int>res;
        res.push_back(queue.top().first);
        int j=1;
        for(int i=k;i<nums.size();i++){
            queue.push({nums[i],i});
            while(!queue.empty()&&queue.top().second<j){
                queue.pop();
            }
            j++;
            res.push_back(queue.top().first);
        }
        return res;
    }
};
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int>q;
        for(int i=0;i<k;i++){
            while(!q.empty()&&nums[q.back()]<=nums[i]){
                q.pop_back();
            }
            q.push_back(i);
        }
        int j=1;
        vector<int>res={nums[q.front()]};
        for(int i=k;i<nums.size();i++){
            while(!q.empty()&&nums[q.back()]<=nums[i]){
                q.pop_back();
            }
            q.push_back(i);
            while(!q.empty()&&q.front()<j){
                q.pop_front();
            }
            j++;
            res.push_back(nums[q.front()]);
        }
        return res;
    }
};