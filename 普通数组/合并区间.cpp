#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    void add(vector<int>&count,int L,int R,int x){
        vector<int>d(count.size());
        d[0]=count[0];
        for(int i=1;i<d.size();i++){
            d[i]=count[i]-count[i-1];
        }
        d[L]+=x;
        if(R+1<d.size()){
            d[R+1]-=x;
        }
        vector<int>pre(d.size());
        pre[0]=d[0];
        for(int i=1;i<d.size();i++){
            pre[i]=pre[i-1]+d[i];
        }
        count=pre;
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int maxright=0;
        for(int i=0;i<intervals.size();i++){
            maxright=max(maxright,intervals[i][1]);
        }
        maxright*=2;
        //cout<<maxright<<endl;
        vector<int>count(maxright+1,0);
        int L,R;
        for(int i=0;i<intervals.size();i++){
            L=intervals[i][0];
            R=intervals[i][1];
            add(count,L*2,R*2,1);
        }
        vector<vector<int>>res;
        vector<int>tmp(2);
        int i=0;
        while(i<=maxright){
            while(i<=maxright&&!count[i]){
                i++;
            }
            if(i>maxright){
                break;
            }
            L=i;
            while(i<=maxright&&count[i]){
                i++;
            }
            R=i-1;
            tmp[0]=L/2;
            tmp[1]=R/2;
            res.push_back(tmp);
        }
        return res;
    }
};