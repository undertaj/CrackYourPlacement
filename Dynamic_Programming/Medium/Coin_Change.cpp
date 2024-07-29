#include <bits/stdc++.h>
using namespace std;

class Solution {
    int dp[10001];
    long long combination(int n, vector<int>& coins){
        if(n == 0) return 0;
        if(dp[n] != -1) {
            return dp[n];
        }
        long long r = INT_MAX,k;
        for(int i: coins){
            if(n >= i) {
                k = combination(n-i,coins);
                if(k >= 0)
                r = r < k ? r : k;
            }
        }
        if(r == INT_MAX) return dp[n] = -10001;
        return dp[n] = 1+r;
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        memset(dp,-1,sizeof(dp));
        long long x = combination(amount,coins);
        if(x < 0){
            return -1;
        }
        return x;
    }
};