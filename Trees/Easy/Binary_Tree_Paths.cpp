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
    vector<string> v;
    void solve(TreeNode* n, string s){
        if(!n) return;
        if(n->right || n->left){
            solve(n->right, s+"->"+to_string(n->val));
            solve(n->left,  s+"->"+to_string(n->val));
            return;
        }
        string ans = s+"->"+to_string(n->val);
        if(ans.length() > 2)
        v.push_back(ans.substr(2));
        else
        v.push_back(ans);
    }
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        solve(root, "");
        return v;
    }
};