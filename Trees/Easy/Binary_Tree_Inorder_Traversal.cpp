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
    void InOrder(TreeNode* r, vector<int>& v) {
        if (r == nullptr)
            return;
        
        InOrder(r->left, v);
        v.push_back(r->val);
        InOrder(r->right, v);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> vec;
        InOrder(root, vec);
        return vec;
    }
};