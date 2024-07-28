#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> dp(n+1,0);
        if(n > 0) dp[1] = 1;
        int t = 1;
        for(int i = 2; i < n+1; i++){
            if(i == t<<1) t<<=1;
            dp[i] = 1 + dp[i-t];
        }
        return dp;
    }
};