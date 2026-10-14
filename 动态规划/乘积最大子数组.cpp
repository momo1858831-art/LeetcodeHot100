#include<iostream>
using namespace std;

class Solution {
public:
    int max(int x,int y,int z){
        int ans;
        ans=x>y?x:y;
        ans=ans>z?ans:z;
        return ans;
    }
    int min(int x,int y,int z){
        int ans;
        ans=x<y?x:y;
        ans=ans<z?ans:z;
        return ans;
    }
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        int dp1[n+1],dp2[n+1];
        dp1[1]=dp2[1]=nums[0];
        int x,y,z;
        int ans=dp1[1];
        for(int i=2;i<=n;i++){
            x=nums[i-1];
            y=x*dp1[i-1];
            z=x*dp2[i-1];
            dp1[i]=max(x,y,z);
            dp2[i]=min(x,y,z);
            if(ans<dp1[i]){
                ans=dp1[i];
            }
        }
        return ans;
    }
};