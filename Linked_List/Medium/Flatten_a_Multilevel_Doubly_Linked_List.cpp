#include <bits/stdc++.h>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};


class Solution {
    Node* flatten1(Node* head) {
        if(head == nullptr){
            return nullptr;
        }
        if(head->child != nullptr){
            Node* p = head->next;
            head->next = head->child;
            head->child->prev = head;
            Node* x = flatten1(head->child);
            head->child = nullptr;
            x->next = p;
            if(p != nullptr)
            p->prev = x;
        }
        if(head->next == nullptr){
            return head;
        }
        return flatten1(head->next);
    }

public:
    Node* flatten(Node* head) {
        Node* p = flatten1(head);
        return head;
    }
};