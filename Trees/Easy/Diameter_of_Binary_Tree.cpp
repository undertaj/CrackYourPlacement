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
    int dd(TreeNode* root, int& ans){
        if(!root) return 0;
        int a = dd(root->left, ans), b = dd(root->right, ans);
        ans = max(ans,a+b);
        return 1 + max(a,b);
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int ans = 0;
        dd(root, ans);
        return ans;
    }
};