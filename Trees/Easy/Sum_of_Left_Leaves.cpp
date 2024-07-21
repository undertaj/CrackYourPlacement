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
    int sumOfLL(TreeNode* root) {
        if(!root) return -1001;
        int left = sumOfLL(root->left);
        int right = sumOfLL(root->right);
        if(left == -1001 && right == -1001){
            return root->val;
        }
        else if(right != -1001 && root->right && !root->right->left && !root->right->right){
            if(left != -1001)
            return left; 
            return 0;
        }
        int a = 0;
        if(left != -1001)
            a += left;
        if(right != -1001)
            a += right;
        return a;
    }
public:
    int sumOfLeftLeaves(TreeNode* root) {
        if(root && !root->left && !root->right) return 0;
        return sumOfLL(root);
    }
};