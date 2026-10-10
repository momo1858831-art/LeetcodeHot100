#include<iostream>
#include<unordered_map>
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
    unordered_map<int,int>hash;
    TreeNode* dfs(vector<int>& preorder, vector<int>& inorder,int start1,int end1,int start2,int end2){
         if(start1>end1){
            return NULL;
        }
        if(start1==end1){
            TreeNode *root=new TreeNode(preorder[start1]);
            return root;
        }
        int mid=hash[preorder[start1]];
        TreeNode *root=new TreeNode(preorder[start1]);
        root->left=dfs(preorder,inorder,start1+1,start1+mid-start2,start2,mid-1);
        root->right=dfs(preorder,inorder,start1+mid-start2+1,end1,mid+1,end2);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n=preorder.size();
        for(int i=0;i<n;i++){
            hash[inorder[i]]=i;
        }
        TreeNode *root=dfs(preorder,inorder,0,n-1,0,n-1);
        return root;
    }
};