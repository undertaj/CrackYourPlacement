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
    void flatten(TreeNode* root) {
        if(!root) return;
        flatten(root->left);
        TreeNode* left = root->left;
        flatten(root->right);
        while(left){
            if(left->right)
            left = left->right;
            else break;
        }
        if(left){
            left->right = root->right;
            root->right = root->left;
            root->left = nullptr;
        }
        return;
    }
};