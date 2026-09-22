#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size(),m=matrix[0].size();
        int i=0,j=m-1;
        int cur=matrix[i][j];
        while(true){
            if(cur==target){
                return true;
            }
            if(cur>target){
                j--;
                if(j<0){
                    break;
                }
                cur=matrix[i][j];
                continue;
            }
            if(cur<target){
                i++;
                if(i>=n){
                    break;
                }
                cur=matrix[i][j];
            }
        }
        return false;
    }
};