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
    priority_queue<int, vector<int>, greater<int>> pq;
    void traverse(TreeNode* root){
        if(!root) return;
        pq.push(root->val);
        traverse(root->left);
        traverse(root->right);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        traverse(root);
        // cout<<pq.top();
        while(--k){
            pq.pop();
        }
        return pq.top();
    }
};