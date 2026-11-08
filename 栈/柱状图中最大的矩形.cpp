#include<iostream>
using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        stack<int>sk;
        vector<int>left(n,-1),right(n,n);
        int t;
        for(int i=0;i<n;i++){
            while(!sk.empty()&&heights[sk.top()]>heights[i]){
                t=sk.top();
                right[t]=i;
                sk.pop();
                if(!sk.empty())
                    left[t]=sk.top(); 
                else
                    left[t]=-1;
            }
            sk.push(i);
        }
        int x;
        if(sk.size()>1){
            x=sk.top();
            sk.pop();
            while(!sk.empty()){
                left[x]=sk.top();
                x=sk.top();
                sk.pop();
            }
        }
        int res=0;
        for(int i=0;i<n;i++){
            if(right[i]==n&&left[i]==-1)
                res=max(res,heights[i]*n);
            else if(right[i]==n)
                res=max(res,heights[i]*(n-1-left[i]));
            else if(left[i]==-1)
                res=max(res,heights[i]*right[i]);
            else
                res=max(res,heights[i]*(right[i]-left[i]-1));
        }
        return res;
    }
};