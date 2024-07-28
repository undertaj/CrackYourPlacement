#include <bits/stdc++.h>
using namespace std;

class Solution {
    // z is zeroes o is ones
    int dp[101][101][601];
    int subset(int z, int o, int index, vector<pair<int,int>>& v){
        if(index == v.size()|| (z == 0 && o == 0))      
        return 0;
        if(dp[z][o][index] != -1)
            return dp[z][o][index];
        int a,b;
        a = subset(z,o,index+1,v);

        if(v[index].first > z or v[index].second > o)  
            return dp[z][o][index] = a;

        b = 1 + subset(z-v[index].first, o-v[index].second,index+1,v);
        int C = max(a,b);
        return dp[z][o][index] = C;
    }
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int m1,n1;
        vector<pair<int,int>> v;
        memset(dp,-1,sizeof(dp));
        for(string s: strs){
            m1 = 0; n1 = 0;
            for(char c: s){
                if(c == '1') m1++; else n1++;
            }
            v.push_back(make_pair(n1,m1));
        }
        return subset(m,n,0,v);
    }
};