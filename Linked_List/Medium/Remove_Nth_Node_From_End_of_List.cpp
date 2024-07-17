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
    //BASIC COUNT TOTAL NODES + SKIP (count-n+1)th NODE from START
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int count = 1;
        ListNode *h = head, *p;
        while(h){
            h = h->next;
            count++;
        }
        h = head;
        if(n == count-1) {
            h = head->next;
            head->next = nullptr;
            return h;
        } 
        int ind = 1;
        n = count-n;
        while(h){
            if(ind + 1 == n){
                p = h;
            }
            if(ind == n){
                p->next = h->next;
            }
            h = h->next;
            ind++;
        }
        return head;
    }
};