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
    ListNode* add(ListNode* l1, ListNode* l2) {
        if(l1 == nullptr && l2 == nullptr) {
            return nullptr;
        }
        if(!l1 || !l2){
            cout<<" unequal\n";
            return nullptr;
        }
        cout<<l1->val<<" "<<l2->val<<"\n";
        ListNode* p = add(l1->next,l2->next), *x;
        if(p && p->val > 9){
            p->val = p->val%10;
            x = new ListNode(l1->val+l2->val+1);
        }
        else {
            x = new ListNode(l1->val+l2->val);
        }
        x->next = p;
        return x;
    }
public:

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *la = l1,*lb = l2;
        int q = 0,p = 0;
        while(la){
            la = la->next;
            p++;
        }
        while(lb){
            lb = lb->next;
            q++;
        }
        if(p < q){
            lb = l1;
            la = l2;
        }
        else{
            lb = l2;
            la = l1;
        }
        p = abs(p-q);
        cout<<p<<" = p\n";
        ListNode* q1;
        while(p--){
            q1 = new ListNode(0);
            q1->next = lb;
            lb = q1;
        }
        ListNode* k = add(lb,la);
        if(k->val > 9){
            k->val = k->val%10;
            ListNode* kk = new ListNode(1);
            kk->next = k;
            k = kk;
        }
        return k;
    }
};