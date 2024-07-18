#include <bits/stdc++.h>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        if(head == nullptr){
            return head;
        }
        queue<int> q;
        ListNode* h = head, *p = nullptr, *g = nullptr, *l = nullptr;
        bool f = false;
        while(h){
            if(h->val >= x && !f){
                f = true;
                g = p;
                l = h;
            }
            while(f && h && h->val < x){
                q.push(h->val);
                h = h->next;
            }
            if(p)
            p->next = h;
            p = h;
            if(h)
            h = h->next;
        }
        // return head;
        if(q.size() > 0) {
            while(!q.empty()) {
                ListNode* x = new ListNode(q.front());
                if(g == nullptr){
                    g = x;
                    head = g;
                }
                else {
                    g->next = x;
                    g = x;
                }
                q.pop();
            }
            g->next = l;
        }
        return head;
    }
};