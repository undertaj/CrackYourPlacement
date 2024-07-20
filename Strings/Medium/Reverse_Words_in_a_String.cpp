#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        string rev ="", word ="";
        for(int i = 0; i < s.length(); i++) {
            int x = (int)s[i];
            if(x != 32) {
                word+=s[i];
            }
            else {
                if(word != "") {
                    rev =  " " + word + rev; 
                }
                word="";
            }
        }
        if(word != "") {
            rev =  " " + word + rev; 
        }
        return rev.substr(1);
    }
};