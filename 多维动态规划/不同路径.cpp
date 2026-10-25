#include<iostream>
using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int>dp(n,1);
        for(int i=1;i<m;i++){
            for(int j=0;j<n;j++){
                if(!j)
                    continue;
                dp[j]=dp[j]+dp[j-1];
            }
        }
        return dp[n-1];
    }
};