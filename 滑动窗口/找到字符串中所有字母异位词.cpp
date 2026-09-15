#include<iostream>
#include<unordered_set>
using namespace std;
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int>res;
        if(p.size()>s.size()){
            return res;
        }
        vector<int>count(26,0);
        for(int i=0;i<p.size();i++){
            count[p[i]-'a']++;
            count[s[i]-'a']--;
        }
        int differ=0;
        for(int i=0;i<26;i++){
            if(count[i]){
                differ++;
            }
        }
        int i=0,j=p.size()-1;
        while(j<s.size()){
            if(!differ){
                res.push_back(i);
            }
            if(count[s[i]-'a']==-1){
                differ--;
            }
            else if(count[s[i]-'a']==0){
                differ++;
            }
            count[s[i]-'a']++;
            i++;
            j++;
            if(j==s.size()){
                break;
            }
            if(count[s[j]-'a']==1){
                differ--;
            }
            else if(count[s[j]-'a']==0){
                differ++;
            }
            count[s[j]-'a']--;
        }
        return res;
    }
};