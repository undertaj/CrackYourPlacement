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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* h = head, *p = nullptr;
        while(h){
            if(!p){
                head = h;
                p = h;
            }
            else if(p->val != h->val){
                p->next = h;
                p = h;
            }
            h = h->next;
        }
        if(p)
        p->next = nullptr;
        return head;
    }
};