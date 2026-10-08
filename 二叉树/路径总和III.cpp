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
    long long count=0;
    unordered_map<long,long>hash;
    long long sum=0;
    void dfs(TreeNode *root,int targetSum){
        if(!root){
            return;
        }
        sum+=root->val;
        if(hash.find(sum-targetSum)!=hash.end()){
            count+=hash[sum-targetSum];
        }
        hash[sum]++;
        dfs(root->left,targetSum);
        if(root->left){
            sum-=root->left->val;
        }
        dfs(root->right,targetSum);
        if(root->right){
            sum-=root->right->val;
        }
        hash[sum]--;

    }
    int pathSum(TreeNode* root, int targetSum) {
        hash[0]=1;
        dfs(root,targetSum);
        return count;
    }
};