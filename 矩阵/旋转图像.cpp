#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int k=0;
        int r1=k,c1=k,r2=k,c2=n-k-1,r3=n-k-1,c3=n-k-1,r4=n-k-1,c4=k;
        int tmp1,tmp2,tmp3;
        while(r1<=r3){
            while(c1<c2){
                tmp1=matrix[r2][c2];
                matrix[r2][c2]=matrix[r1][c1];
                tmp2=matrix[r3][c3];
                matrix[r3][c3]=tmp1;
                tmp3=matrix[r4][c4];
                matrix[r4][c4]=tmp2;
                matrix[r1][c1]=tmp3;
                c1++;
                r2++;
                c3--;
                r4--;
            }
            k++;
            r1=k,c1=k,r2=k,c2=n-k-1,r3=n-k-1,c3=n-k-1,r4=n-k-1,c4=k;
        }
    }
};