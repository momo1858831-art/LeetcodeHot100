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

class A {
public:
    TreeNode *root;
    unordered_map<TreeNode*,int>count;
    A(){

    }
    A(TreeNode *root){
        this->root=root;
        dfs(root);
    }
    int dfs(TreeNode *root){
        if(!root){
            return 0;
        }
        int lc=dfs(root->left);
        int rc=dfs(root->right);
        count[root]=lc+rc+1;
        return lc+rc+1;
    }
    int kthSmallest(TreeNode *root,int k){
        int lc=0;
        if(root->left){
            lc=count[root->left];
        }
        if(k==lc+1){
            return root->val;
        }
        if(k<lc+1){
            return kthSmallest(root->left,k);
        }
        return kthSmallest(root->right,k-lc-1);
    }
};
class Solution{
public:
    unique_ptr<A> a;
    int kthSmallest(TreeNode *root,int k){
        if(!a||a->root!=root){
            a.reset(new A(root));
        }
        return a->kthSmallest(root,k);
    }
};