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
public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if(root1 && root2){
            root1->val += root2->val;
            root1->left = mergeTrees(root1->left,root2->left);
            root1->right = mergeTrees(root1->right,root2->right);
            return root1;
        }
        else if(!root1 && root2){
            TreeNode* x = new TreeNode(root2->val);
            x->left = mergeTrees(nullptr,root2->left);
            x->right = mergeTrees(nullptr,root2->right);
            return x;
        }
        else if(root1 && !root2){
            root1->left = mergeTrees(root1->left,nullptr);
            root1->right = mergeTrees(root1->right,nullptr);
            return root1;
        }
        return nullptr;
    }
};