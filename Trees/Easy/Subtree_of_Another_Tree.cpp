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
    bool check(TreeNode* root, TreeNode* subRoot){
        if((!root || !subRoot) && (!root && !subRoot)) {
            return true;
        }
        else if(root && subRoot) {
            return root->val == subRoot->val && check(root->left,subRoot->left) && check(root->right,subRoot->right);
        }
        return false;
    }
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        bool c = check(root,subRoot);
        if(!root) return c;
        return c || isSubtree(root->left,subRoot) || isSubtree(root->right,subRoot);
    }
};