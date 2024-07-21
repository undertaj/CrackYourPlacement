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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* head = new ListNode();
        ListNode* p = head;
        if(list1 == nullptr && list2 == nullptr) 
        return nullptr;
        do {
            
            if(list1 != nullptr && list2 != nullptr) {
                if(list1->val < list2->val) {
                    p->next = list1;
                    list1 = list1->next;
                }
                else {
                    p->next = list2;
                    list2 = list2->next;
                }
            }
            else if(list1 == nullptr) {
                //cout<<"case3\n";
                p->next = list2;
                //if(list2 != nullptr)
                list2 = list2->next;
            }
            else {
                p->next = list1;

                if(list1 != nullptr)
                list1 = list1->next;
            }
            
            p = p->next; 
            //cout<<p->val<<" = value of p \n";   
        } while(list1 != nullptr || list2 != nullptr);
        // if(head->next != nullptr)
        // cout<<head->next->val<<"value\n";
        return head->next;
    }
};