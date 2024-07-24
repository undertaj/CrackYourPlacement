#include <bits/stdc++.h>
using namespace std;


// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
    bool hasPath(TreeNode* root, int targetSum, int sum) {
        if(!root) return 0;
        if(root && !root->left && !root->right){
            return  root->val+sum == targetSum;
        }
        return hasPath(root->left,targetSum,sum+root->val) ||
        hasPath(root->right,targetSum,sum+root->val);
    }
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        return hasPath(root,targetSum, 0);
    }
};