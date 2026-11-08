#include<iostream>
using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        stack<int>sk;
        int t;
        int res=0;
        for(int i=0;i<n;i++){
            while(!sk.empty()&&heights[sk.top()]>heights[i]){
                t=sk.top();
                sk.pop();
                if(!sk.empty())
                    res=max(res,heights[t]*(i-sk.top()-1));
                else
                    res=max(res,heights[t]*i);
            }
            sk.push(i);
        }
        while(!sk.empty()){
            t=sk.top();
            sk.pop();
            if(!sk.empty())
                res=max(res,heights[t]*(n-sk.top()-1));
            else
                res=max(res,heights[t]*n);
        }
        return res;
    }
};