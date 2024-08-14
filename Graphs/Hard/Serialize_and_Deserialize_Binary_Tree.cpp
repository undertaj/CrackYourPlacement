#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root == nullptr) return ".";
        return to_string(root->val)+"("+serialize(root->left)+","+serialize(root->right)+")";
    }

    pair<TreeNode*,TreeNode*> pp(string s, int i) {
        int l = s.length(), n = 0;
        TreeNode* leftT, *rightT;
        bool neg = false;
        while(i < l) {
            if(s[i] == '(') {
                pair<TreeNode*,TreeNode*> pair1;
                // cout<<"Val = "<<n<<"\n";
                pair1 = pp(s, i+1);
                int c = 1;
                i++;
                while(i < s.length() && c != 0) {
                    if(s[i] == '(')c++;
                    if(s[i] == ')') {
                        c--;
                    }
                    i++; 
                } 
                i+=1;
                // cout<<i<<" after\n";
                TreeNode* x = new TreeNode(neg ? -n: n);
                x->left = pair1.first;
                x->right = pair1.second;
                leftT = x;  
                // return x;
                break;
            }
            else if(s[i] == ',') {
                if(n == -1) {
                    leftT = nullptr;
                }
                else {
                    leftT = new TreeNode(n);
                }
                i++;
                break;
            }
            else {
                if(s[i] == '.'){
                    n = -1;
                    neg = false;
                }
                else {
                    if(s[i] == '-') {
                        neg = true;
                    }
                    else {

                        n = n*10 + (s[i]-'0');
                    }
                }
            }
            i++;
        }
        // cout<<"Middle: "<<n<<"\n";
        n = 0;
        neg = false;
        while(i < l) {
            if(s[i] == '('){
                pair<TreeNode*,TreeNode*> pair1;
                // cout<<"Val = "<<n<<"\n";
                pair1 = pp(s, i+1);
                int c = 1;
                i++;
                while( i < s.length() && c != 0) {
                    if(s[i] == '(') c++;
                    if(s[i] == ')') c--;
                    i++;
                }
                i++;
                // i++;
                TreeNode* x = new TreeNode(neg ? -n : n);
                x->left = pair1.first;
                x->right = pair1.second;
                rightT = x;
                // cout<<"RightT = "<<n<<"\n";
                return make_pair(leftT,rightT);
            }
            else if(s[i] == ')') {
                if(n == -1) {
                    rightT = nullptr;
                }
                else {

                    rightT = new TreeNode(neg ? -n : n);
                }
                // cout<<"RightT2 = "<<n<<"\n";
                return make_pair(leftT, rightT);
                // n = 0;
                // neg = false;
                // i++;
                // break;
            }
            else {
                if(s[i] == '.'){
                    n = -1;
                    neg = false;
                }
                else {
                    if(s[i] == '-') {
                        neg = true;
                    }
                    else
                    n = n*10 + (s[i]-'0');
                }
            }
            i++;
        }
        // cout<<n<<" = n\n";
        return make_pair(leftT,rightT);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        cout<<data<<"\n";
        int l = data.length(), n = 0, i = 0;
        if(data == ".") return nullptr;
        bool neg = false;
        while(i < l){
            if(data[i] == '(') {
                pair<TreeNode*,TreeNode*> pair1;
                pair1 = pp(data, i+1);
                
                TreeNode* x = new TreeNode(neg ? -n : n);
                x->left = pair1.first;
                x->right = pair1.second;
                return x;
            }
            else {
                if(data[i] == '-'){
                    neg = true;
                }
                else
                n = n*10 + (data[i]-'0');
                
            }
            i++;
        }
        return nullptr;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));