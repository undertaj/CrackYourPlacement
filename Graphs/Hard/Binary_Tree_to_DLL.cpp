#include <bits/stdc++.h>
using namespace std;

// Structure for tree and linked list
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};
 

// This function should return head to the DLL
class Solution {
    Node* list(Node* root, bool isLeft, int check) {
        if(!root) return nullptr;
        Node* x = list(root->left,true, 0);
        Node* y = list(root->right, false, 0);
        if(x){
            x->right = root;
            root->left = x;
        }
        if(y){
            y->left = root;
            root->right = y;
        }
        if(check){
            return root;
        }
        if(isLeft){
            if(y){
                while(y->right){
                    y = y->right;
                }
                return y;
            }
            return root;
        }
        else {
            if(x){
                while(x->left){
                    x = x->left;
                }
                return x;
            }
            return root;
        }
    }
  public:
    Node* bToDLL(Node* root) {
        Node* x = list(root,true,1);
        while(root->left){
            root = root->left;
        }
        return root;
    }
};