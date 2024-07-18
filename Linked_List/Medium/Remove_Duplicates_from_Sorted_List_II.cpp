#include <bits/stdc++.h>
using namespace std;

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
class Solution {
public:
    /*
    CHECK NODES FOR PREVIOUS AND NEXT NODE, IF NOT SAME ADD TO NEW LIST;
    Time Complexity: O(N)
    Space Complexity: O(1)
    */
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == nullptr) return head;
        ListNode *h = head, *p = nullptr, *start = nullptr, *k, *head1;
        head1 = start;
        while(h){
            if((!p && ((h->next &&  h->val != h->next->val) || !h->next))|| (p && p->val != h->val && ((h->next &&  h->val != h->next->val) || !h->next))){
                k = new ListNode(h->val);
                if(start) 
                    start->next = k;
                else
                    head1 = k;
                start = k;
            }
            p = h;
            h = h->next;
        }
        if(start)
        start->next = nullptr;
        return head1;
    }
};