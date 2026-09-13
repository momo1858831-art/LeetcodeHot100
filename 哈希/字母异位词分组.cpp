#include<iostream>
#include<vector>
#include<map>
#include<string>
#include<algorithm>
using namespace std;
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>>ans;
        if(strs.size()==0){
            return ans;
        }
        if(strs.size()==1){
            ans.push_back(strs);
            return ans;
        }
        map<vector<int>,vector<string>>map;
        for(int i=0;i<strs.size();i++){
            string str=strs[i];
            vector<int>count(26);
            for(int j=0;j<str.length();j++){
                count[str[j]-'a']++;
            }
            map[count].push_back(str);
        }
        for(auto i:map){
            ans.push_back(i.second);
        }
        return ans;
    }
};