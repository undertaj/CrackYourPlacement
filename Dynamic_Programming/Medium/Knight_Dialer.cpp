#include <bits/stdc++.h>
using namespace std;
# define M 1000000007


class Solution {
public:
    map<int,vector<int>> mp = {
        {0, {4,6}},
        {1, {6,8}},
        {2, {7,9}},
        {3, {4,8}},
        {4, {0,3,9}},
        {5, {}},
        {6, {1,7,0}},
        {7, {2,6}},
        {8, {1,3}},
        {9, {2,4}},
    };
    vector<vector<int>> dp;
    int findC(int n, int l) {
        if(l == 1) {
            dp[n][l] = mp[n].size();
            return dp[n][l];
        }
        if(dp[n][l] == -1) {
            int ans = 0;
            for(int i = 0; i < mp[n].size(); i++) {
                ans = (ans%M + findC(mp[n][i], l-1))%M;
            }
            return dp[n][l] = ans;
        }
        else
        return dp[n][l];
        
        
    }
    int knightDialer(int n) {
        dp = vector<vector<int>>(10, vector<int>(5001, -1));
        int ans = 0;
        if(n == 1)
        return 10;
        for(int j = 0; j < 10; j++) {
            ans = (ans%M + findC(j, n-1))%M;
        }
        return ans;
    }
};