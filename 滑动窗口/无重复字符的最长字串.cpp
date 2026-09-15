#include<iostream>
#include<unordered_set>
using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int res=1;
        if(s.size()==1){
            return 1;
        }
        if(s.size()==0){
            return 0;
        }
        int left=0,right;
        unordered_set<char>hash;
        hash.insert(s[left]);
        for(right=1;right<s.size();right++){
            if(hash.find(s[right])!=hash.end()){
                while(s[left]!=s[right]){
                    hash.erase(s[left]);
                    left++;
                }
                left++;
            }
            else{
                hash.insert(s[right]);
            }
            res=max(res,right-left+1);
        }
        return res;
    }
};