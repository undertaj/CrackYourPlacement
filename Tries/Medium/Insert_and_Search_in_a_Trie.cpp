#include <bits/stdc++.h>
using namespace std;
#define ALPHABET_SIZE 26

// trie node
struct TrieNode {
    struct TrieNode *children[ALPHABET_SIZE];

    // isLeaf is true if the node represents
    // end of a word
    bool isLeaf;
};

class Solution
{
    public:
        //Function to insert string into TRIE.
        void insert(struct TrieNode *root, string key)
        {
            TrieNode* k;
            for(int i = 0 ; i < key.length(); i++){
                if(root->children[key[i]-'a']){
                    root = root->children[key[i]-'a'];
                }
                else {
                    k = new TrieNode();
                    root->children[key[i]-'a'] = k;
                    root = k;
                }
            }
            root->isLeaf = true;
        }
        
        //Function to use TRIE data structure and search the given string.
        bool search(struct TrieNode *root, string key) 
        {
            for(int i = 0 ; i < key.length(); i++){
                if(root->children[key[i]-'a']){
                    root = root->children[key[i]-'a'];
                }
                else {
                    return false;
                }
            }
            if(root->isLeaf)
            return true;
        }
};