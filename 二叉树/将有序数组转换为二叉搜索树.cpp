#include<iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

class Solution {
public:
    TreeNode* sorted(vector<int>&nums,int start,int end){
        if(start>end){
            return NULL;
        }
        if(start==end){
            TreeNode *root=new TreeNode(nums[start]);
            return root;
        }
        int mid=(start+end)/2;
        TreeNode *root=new TreeNode(nums[mid]);
        root->left=sorted(nums,start,mid-1);
        root->right=sorted(nums,mid+1,end);
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(nums.size()==0){
            return NULL;
        }
        if(nums.size()==1){
            TreeNode *root=new TreeNode(nums[0]);
            return root;
        }
        TreeNode *root=sorted(nums,0,nums.size()-1);
        return root;
    }
};