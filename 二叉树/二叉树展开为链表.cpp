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
    void flatten(TreeNode* root) {
        TreeNode *r=root;
        while(r){
            if(r->left){
                TreeNode *t=r->left;
                while(t->right){
                    t=t->right;
                }
                t->right=r->right;
                r->right=r->left;
                r->left=NULL;
                r=r->right;
            }
            else{
                r=r->right;
            }
        }
    }
};