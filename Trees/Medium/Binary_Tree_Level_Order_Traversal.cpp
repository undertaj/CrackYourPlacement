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
    void solve(TreeNode* root, vector<vector<int>>& v,int k) {
        if(!root) return;
        if(v.size() <= k)
            v.push_back({root->val});
        else
            v[k].push_back(root->val);
        solve(root->left,v,k+1);
        solve(root->right,v,k+1);
    }
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        int k = 0;
        vector<vector<int>> v = {};
        solve(root,v,k);
        return v;
    }
};