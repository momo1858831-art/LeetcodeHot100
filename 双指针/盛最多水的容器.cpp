#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int maxArea(vector<int>& height) {
        int i=0,j=height.size()-1;
        int rain=0;
        while(i<j){
            int cur=(j-i)*min(height[i],height[j]);
            rain=max(rain,cur);
            if(height[i]<height[j]){
                i++;
            }
            else{
                j--;
            }
        }
        return rain;
    }
};