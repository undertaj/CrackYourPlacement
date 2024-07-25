#include <bits/stdc++.h>
using namespace std;


// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};


class Solution {
    void addNode(vector<vector<Node*>>& v, Node* n, int i){
        if(!n){
            return;
        }
        addNode(v,n->left, i+1);
        v[i].push_back(n);
        addNode(v,n->right, i+1);
    }
public:
    Node* connect(Node* root) {
        vector<vector<Node*>> v(4096);
        addNode(v, root, 0);
        for(int i = 0; i < 4096; i++) {
            if(v[i].size() == 0) return root;
            for(int j = 1; j < v[i].size(); j++) {
                v[i][j-1]->next = v[i][j];
            }
        }
        return root;
    }
};