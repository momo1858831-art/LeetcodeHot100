#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
class Solution {
public:
    string minWindow(string s, string t) {
        if(s.size()<t.size()){
            return "";
        }
        unordered_map<char,int>hash;
        for(int i=0;i<t.size();i++){
            hash[t[i]]++;
        }
        int differ=0;
        for(int i=0;i<t.size();i++){
            if(hash.find(s[i])==hash.end()){
                continue;
            }
            hash[s[i]]--;
        }
        for(auto i:hash){
            if(i.second>0){
                differ++;
            }
        }
        int i=0,j=t.size()-1;
        int res=s.size(),start=0,end=s.size()-1;
        int flag=0;
        while(j<s.size()){
            while(differ==0){
                flag=1;
                if(j-i+1<res){
                    res=j-i+1;
                    start=i;
                    end=j;
                }
                if(hash.find(s[i])!=hash.end()){
                    hash[s[i]]++;
                    if(hash[s[i]]>0){
                        differ++;
                    }
                }
                i++;
            }
            j++;
            if(j==s.size()){
                break;
            }
            if(hash.find(s[j])!=hash.end()){
                hash[s[j]]--;
                if(hash[s[j]]==0){
                    differ--;
                }
            }
        }
        if(!flag){
            return "";
        }
        string ans="";
        for(int k=start;k<=end;k++){
            ans.push_back(s[k]);
        }
        return ans;
    }
};