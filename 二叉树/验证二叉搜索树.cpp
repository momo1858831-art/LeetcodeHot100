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
    long pre=-pow(2,31)-1;
    bool dfs(TreeNode *root){
        if(!root){
            return true;
        }
        bool l=dfs(root->left);
        if(!l){
            return false;
        }
        if(root->val<=pre){
            return false;
        }
        pre=root->val;
        bool r=dfs(root->right);
        return r;
    }
    bool isValidBST(TreeNode* root) {
        if(!root){
            return true;
        }
        return dfs(root);
    }
};