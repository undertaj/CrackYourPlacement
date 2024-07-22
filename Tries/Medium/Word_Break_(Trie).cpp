#include <bits/stdc++.h>
using namespace std;

//Definition of TrieNode struct
struct TrieNode{
    TrieNode* child[26];
    bool end;
    TrieNode() {
        for(int i = 0; i < 26; i++) child[i] = nullptr;
        end = false;
    }
};

class Solution{
    TrieNode* root;
    public:
    // A : given string to search
    // B : vector of available strings
    void addWord(string s){
        TrieNode* r = root,*k;
        for(int i = 0; i < s.length(); i++) {
            if(r->child[s[i]-'a']) {
                r = r->child[s[i]-'a'];
            }
            else {
                k = new TrieNode();
                r->child[s[i]-'a'] = k;
                r = k;
            }
        }
        r->end = true;
    }
    
    bool searchWord(TrieNode* k, string s, int i){
        bool b = false;
        if(i == s.length()) return true;
        if(k->child[s[i]-'a']) {
            if(k->child[s[i]-'a']->end){
                TrieNode* copy = root;
                b = b || searchWord(copy, s,i+1);
            }
            else if(i == s.length()-1) {
                return false;
            }
            b = b || searchWord(k->child[s[i]-'a'],s,i+1);
        }
        return b;
    }
    
    int wordBreak(string A, vector<string> &B) {
        //code here
        root = new TrieNode();
        for(int i = 0; i < B.size(); i++) {
            addWord(B[i]);
        }
        TrieNode* cpy = root;
        return searchWord(cpy,A,0);
        
    }
};