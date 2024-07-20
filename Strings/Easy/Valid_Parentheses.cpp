#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        map<char,char> mp = {
            {'(',')'},
            {'{','}'},
            {'[',']'}
        };
        for(int i = 0; i < s.length(); i++) {
            if(!st.empty() && s[i] == mp[st.top()]) {
                st.pop();
            }
            else {
                st.push(s[i]);
            }
        }
        if(st.empty()) return true;
        else return false;
    }
};