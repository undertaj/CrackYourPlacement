#include <bits/stdc++.h>
using namespace std;


// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
    bool solve(ListNode* head, int k){
        if(head == nullptr) return false;
        if(k > 10000){
            return true;
        }
        return solve(head->next, k+1);
    }
public:
    bool hasCycle(ListNode *head) {
        return solve(head,0);
    }
};