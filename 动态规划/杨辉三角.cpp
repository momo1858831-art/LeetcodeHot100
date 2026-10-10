#include<iostream>
using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>res(numRows);
        int pre=0,i=1;
        res[0].push_back(1);
        while(i<numRows){
            for(int j=0;j<=i;j++){
                if(j==0||j==i){
                    res[i].push_back(1);
                    continue;
                }
                res[i].push_back(res[i-1][j-1]+res[i-1][j]);
            }
            pre=i;
            i++;
        }
        return res;
    }
};