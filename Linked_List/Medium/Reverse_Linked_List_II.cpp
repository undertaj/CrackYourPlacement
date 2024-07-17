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
    //USED STACK to reverse range
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(left == right) return head;
        ListNode* h = head;
        ListNode* p;
        stack<int> st;
        int index = 1;
        while(h) {
            if(index >= left && index <= right) {
                st.push(h->val);
            }
            h = h->next;
            index++;
        }
        int max = index;
        index = 1;
        h = head;
        while(h) {
            if(index < left) {
                p = h;
            }
            if(index >= left && index <= right) {  
                ListNode* x = new ListNode(st.top());
                st.pop();
                if(left == 1 && index == left) {
                    p = x;
                    head = x;
                    index++;
                    h = h->next;
                    continue;
                }
                p->next = x;
                cout<<p->next->val;
                p = x;
            }
            if(index >= right && right != max-1) {
                p->next = h->next;
                break;
            }
            h = h->next;
            index++;
        }
        return head;
    }
};