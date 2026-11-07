#include<iostream>
using namespace std;
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int>sk;
        int n=temperatures.size();
        vector<int>res(n,0);
        sk.push(0);
        int i=1,j;
        while(i<n){
            while((i<n)&&!sk.empty()&&(temperatures[i]>temperatures[sk.top()])){
                j=sk.top();
                res[j]=i-j;
                sk.pop();
            }
            if(i==n)
                break;
            sk.push(i++);
        }
        return res;
    }
};