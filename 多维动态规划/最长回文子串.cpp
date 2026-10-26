#include<iostream>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.length();
        if(n==1){
            return s;
        }
        int start=0,len=1,j;
        vector<bool>dp(n,false);
        for(int i=n-1;i>=0;i--){
            for(int j=n-1;j>=i;j--){
                if(i==j){
                    dp[j]=true;
                }
                else if(i+1==j){
                    dp[j]=(s[i]==s[j]);
                }
                else{
                    dp[j]=dp[j-1]&&(s[i]==s[j]);
                }
                if(dp[j]&&(j-i+1)>len){
                    len=j-i+1;
                    start=i;
                }
            }
        }
        string str="";
        for(int i=start;i<start+len;i++){
            str+=s[i];
        }
        return str;
    }
};