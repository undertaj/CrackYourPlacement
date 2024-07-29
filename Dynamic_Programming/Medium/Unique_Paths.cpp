#include <bits/stdc++.h>
using namespace std;

class Solution {
    int dp[100][100];
    int findUnique(int i, int j, int& m,int& n){
        if(i == m || j == n) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        return dp[i][j] = findUnique(i,j+1,m,n)+findUnique(i+1,j,m,n);
    }
public:
    int uniquePaths(int m, int n) {
        memset(dp,-1,sizeof(dp));
        dp[m-1][n-1] = 1;
        return findUnique(0,0,m,n);
    }
};