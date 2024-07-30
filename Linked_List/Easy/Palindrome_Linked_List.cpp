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
    int arr[100000];
    bool solve(int i, ListNode* node, int n){
        if(i > n/2){
            return true;
        }
        if(arr[i] == arr[n-i-1]){
            return solve(i+1,node->next, n);
        }
        else {
            return false;
        }
    }
public:
    bool isPalindrome(ListNode* head) {
        int i = 0;
        ListNode* h = head;
        while(h) {
            arr[i] = h->val;
            i++;
            h = h->next;
        }
        return solve(0,head,i);
    }
};