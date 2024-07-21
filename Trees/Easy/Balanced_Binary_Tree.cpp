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
    pair<int,bool> solve(TreeNode* root){
        if(!root) return make_pair(0,true);
        pair<int,bool> a = solve(root->left), b = solve(root->right);
        bool check = a.second && b.second;
        if(abs(a.first-b.first) > 1) check = false;
        return make_pair(1+max(a.first,b.first),check);
    }
public:
    bool isBalanced(TreeNode* root) {
        pair<int,bool> c = solve(root);
        return c.second;
    }
};