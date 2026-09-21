#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int u=0,d=matrix.size()-1,l=0,r=matrix[0].size()-1;
        vector<int>res;
        while(true){
            if(l>r){
                break;
            }
            for(int i=l;i<=r;i++){
                res.push_back(matrix[u][i]);
            }
            u++;
            if(u>d){
                break;
            }
            for(int i=u;i<=d;i++){
                res.push_back(matrix[i][r]);
            }
            r--;
            if(l>r){
                break;
            }
            for(int i=r;i>=l;i--){
                res.push_back(matrix[d][i]);
            }
            d--;
            if(u>d){
                break;
            }
            for(int i=d;i>=u;i--){
                res.push_back(matrix[i][l]);
            }
            l++;
        }
        return res;
    }
};