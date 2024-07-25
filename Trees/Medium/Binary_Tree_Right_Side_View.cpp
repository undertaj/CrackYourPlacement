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
    vector<int> rightSideView(TreeNode* root) {
        if(!root) return {};
        vector<int> a = rightSideView(root->left);
        vector<int> b = rightSideView(root->right);
        vector<int> c = {root->val};
        int i = 0, j = 0;
        while(i < a.size() || j < b.size()){
            if(j < b.size()) {
                c.push_back(b[j]);
            }
            else if(i < a.size()){
                c.push_back(a[i]);
            }
            else return c;
            i++;
            j++;
        }
        return c;
    }
};
