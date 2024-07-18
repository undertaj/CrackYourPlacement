
#include <bits/stdc++.h>
using namespace std;

// Node is defined as
struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};


class Solution
{
    public:
    //Function to sort a linked list of 0s, 1s and 2s.
    Node* segregate(Node *head) {
        Node* h = head, *p = nullptr;
        int zero = 0, one = 0, two = 0;
        while(h){
            if(h->data == 0)
                zero++;
            else if(h->data == 1)
                one++;
            else
                two++;
            h = h->next;
        }
        int count = zero+one+two;
        while(count--){
            if(zero > 0){
                h = new Node(0);
                zero--;
            }
            else if(one > 0){
                h = new Node(1);
                one--;
            }
            else {
                h = new Node(2);
                two--;
            }
            if(!p) {
                p = h;
                head = h;
            }
            else {
                p->next = h;
                p = h;
            }
        }
        return head;
    }
};