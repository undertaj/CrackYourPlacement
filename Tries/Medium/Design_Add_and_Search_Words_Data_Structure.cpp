#include <bits/stdc++.h>
using namespace std;

//Definition for Trie structure
struct TrieNode {
    TrieNode* childNode[26];
    bool wordEnd;
    TrieNode() {
        wordEnd = false;
        for (int i = 0; i < 26; i++) {
            childNode[i] = NULL;
        }
    }
};


class WordDictionary {
    TrieNode* root;
public:
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* r = root, *k;
        for(int i = 0; i < word.length(); i++) {
            if(r->childNode[word[i]-'a'] == nullptr){
                k = new TrieNode();
                r->childNode[word[i]-'a'] = k;
                r = k;
            }
            else {
                r = r->childNode[word[i]-'a'];
                k = r;
            }
        }
        k->wordEnd = true;
    }
    bool recurSearch(TrieNode* r, string word, int i){
        if(i == word.length()){
            return r->wordEnd;
        } 
        if(word[i] == '.'){
            bool k = false;
            for(int j = 0; j < 26; j++) {
                if(r->childNode[j] != nullptr){
                    k = k || recurSearch(r->childNode[j],word,i+1);
                }
            }
            // cout<<k<<" =k\n";
            if(!k){
                return false;
            }
            return true;
        }
        if(r->childNode[word[i]-'a'] == nullptr){
            return false;
        }
        else {
            return recurSearch(r->childNode[word[i]-'a'],word,i+1);
        }
    }
    bool search(string word) {
        TrieNode* r = root;
        return recurSearch(r,word,0);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */