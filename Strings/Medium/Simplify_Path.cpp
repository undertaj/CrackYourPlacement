#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        int n = path.length();
        string c = "";
        stack<string> st;
        for(int i = 0; i < n; i++) {
            if(path[i] == '/') {
                if(c != "") {
                    if(c == "..") {
                        if(!st.empty()) {
                            st.pop();
                        }
                    }
                    else if(c == ".") {;}
                    else {st.push(c);}
                }
                c = "";
            }
            else {
                c = c + path[i];

            }
        }
        if(c != "") {
            if(c == "..") {
                if(st.size())
                st.pop();
            }
            else if(c == ".") ;
            else st.push(c);
        }
        string ans = "";
        while(!st.empty()) {
            ans = "/" + st.top() + ans;
            st.pop();
        }
        if(ans == "") ans = "/";
        return ans;
    }
};