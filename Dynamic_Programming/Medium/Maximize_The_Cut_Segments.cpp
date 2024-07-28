#include <bits/stdc++.h>
using namespace std;


class Solution
{
    long long dp[10001];
    int mc(int n, int x, int y, int z) {
        if(n == 0) return dp[0] = 0;
        if(n < x && n < y && n < z) return INT_MIN;
        if(dp[n] != -1) return dp[n];
        long long a, b, c;
        a = mc(n-x,x,y,z);
        b = mc(n-y,x,y,z);
        c = mc(n-z,x,y,z); 
        return dp[n] = 1 + max(a,max(b,c));
    }
    public:
    //Function to find the maximum number of cuts.
    int maximizeTheCuts(int n, int x, int y, int z)
    {
        memset(dp,-1,sizeof(dp));
        int val = mc(n,x,y,z);
        if( val < 0) val = 0;
        return val;
    }
};