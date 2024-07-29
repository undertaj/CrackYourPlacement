#include <bits/stdc++.h>
using namespace std;

class Solution {
    int dp[101];
    int decode(int index,string& s){
        int i = index;
        if(index == s.length()) return 1;
        if(dp[index] != -1) return dp[index];
        if(s[i] == '0'){
            return dp[index] = 0;
        }
        int n1 = (s[i]-'0');
        if(i == s.length()-1) return 1;
        int n2 = n1*10+(s[i+1]-'0');
        if(i+1 < s.length() && n2 >= 10 && n2 <= 26)
        return dp[index] = decode(index+1,s)+decode(index+2,s);
        else 
        return dp[index] = decode(index+1,s);
    }
public:
    int numDecodings(string s) {
        memset(dp,-1,sizeof(dp));
        return decode(0,s);
    }
};