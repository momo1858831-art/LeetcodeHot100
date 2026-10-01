#include<iostream>
#include<stack>
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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>res;
        stack<pair<int,TreeNode*>>s;
        int white=0,gray=1;
        s.push({white,root});
        int color;
        TreeNode *tree;
        while(!s.empty()){
            color=s.top().first;
            tree=s.top().second;
            s.pop();
            if(!tree){
                continue;
            }
            if(color==white){
                s.push({white,tree->right});
                s.push({gray,tree});
                s.push({white,tree->right});
                continue;
            }
            res.push_back(tree->val);
        }
        return res;
    }
};