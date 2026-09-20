#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int flag1=0,flag2=0;
        for(int i=0;i<matrix[0].size();i++){
            if(!matrix[0][i]){
                flag1=1;
                break;
            }
        }
        for(int i=0;i<matrix.size();i++){
            if(!matrix[i][0]){
                flag2=1;
                break;
            }
        }
        for(int i=1;i<matrix.size();i++){
            for(int j=1;j<matrix[0].size();j++){
                if(!matrix[i][j]){
                    matrix[i][0]=0;
                    matrix[0][j]=0;
                }
            }
        }
        for(int i=1;i<matrix.size();i++){
            for(int j=1;j<matrix[0].size();j++){
                if(!matrix[i][0]||!matrix[0][j]){
                    matrix[i][j]=0;
                }
            }
        }
        if(flag1){
            for(int i=0;i<matrix[0].size();i++){
                matrix[0][i]=0;
            }
        }
        if(flag2){
            for(int i=0;i<matrix.size();i++){
                matrix[i][0]=0;
            }
        }
    }
};