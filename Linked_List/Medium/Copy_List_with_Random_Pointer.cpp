#include <bits/stdc++.h>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};


class Solution {
public:
    Node* copyRandomList(Node* h) {
        map<Node*,Node*> mp;
        Node* head = h;
        if(head == nullptr) return nullptr;
        while(head != nullptr) {
            Node* x = new Node(head->val);
            mp[head] = x;
            head = head->next;
            x->next = head;
        }
        head = h;
        Node* dl = mp[head];
        while(head != nullptr) {
            Node* x = mp[head];
            if(x->next)
            x->next = mp[x->next];
            if(head->random != nullptr) {
                x->random = mp[head->random];
            }
            else {
                x->random = nullptr;
            }
            head = head->next;
        }
        return dl;
    }
};