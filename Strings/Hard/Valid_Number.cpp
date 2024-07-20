#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    //  UTILIZED REGEX FUNCTION
    bool isNumber(string s) {
        int leng = s.length();
        regex integer("([+-][0-9]+|[+-]{0}[0-9]+)([eE]{1}[+-]{0,1}[0-9]+|[eE]{0})");
        smatch m;
        if(regex_search(s,m,integer) == true){
            for(auto x:m) {
                if(x.length() == leng) 
                    return true;
            }
        }
        smatch m1;
        regex decimal("[+-]{0,1}([0-9]+[.]{1}|[.]{1}[0-9]+)[0-9]*([eE]{1}[+-]{0,1}[0-9]+|[eE]{0})");
        if(regex_search(s,m1,decimal) == true){
            for(auto x:m1) {
                if(x.length() == leng) 
                    return true;
            }
        }
        return false;
    }
};