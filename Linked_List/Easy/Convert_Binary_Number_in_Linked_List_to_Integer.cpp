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
    int getDecimalValue(ListNode* head1) {
        int num = 0;
        ListNode* head = head1;
        while(head) {
            num<<=1;
            if(head->val) 
                num += 1;
            head = head->next;
        }
        return num;
    }
};