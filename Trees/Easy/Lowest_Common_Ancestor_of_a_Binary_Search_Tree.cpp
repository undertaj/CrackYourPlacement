#include <bits/stdc++.h>
using namespace std;


// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
    TreeNode* kk;
public:
    void dfs(TreeNode* root, int& target, map<int,int>& mp, bool& cc) {
        if(root == nullptr) {
            return;
        }
        if(mp[root->val] == 1 && !cc) {
            kk = root;
        }

        if(root->val < target) {
            dfs(root->right, target,mp, cc);
        }
        else if(root->val > target) {
            dfs(root->left, target, mp, cc);
        }
        else {
            if(cc) {
                mp[root->val] = 1;
            }
            return;
        }
        
        if(cc) {
            mp[root->val] = 1;
        }
        
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        map<int,int> mp;
        kk = root;
        bool check = true;
        dfs(root, p->val, mp, check);
        check = false;
        dfs(root, q->val, mp, check);
        return kk;
    }
};