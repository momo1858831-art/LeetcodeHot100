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
    void bfs(TreeNode *root,vector<int>&res){
        if(!root){
            return;
        }
        queue<TreeNode*>q;
        q.push(root);
        TreeNode *t;
        int sz;
        while(!q.empty()){
            sz=q.size();
            while(sz--){
                t=q.front();
                q.pop();
                if(t->left){
                    q.push(t->left);
                }
                if(t->right){
                    q.push(t->right);
                }
                if(!sz){
                    res.push_back(t->val);
                }
            }
        }
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int>res;
        bfs(root,res);
        return res;
    }
};