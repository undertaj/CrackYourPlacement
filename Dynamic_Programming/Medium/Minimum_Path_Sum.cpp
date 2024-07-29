#include <bits/stdc++.h>
using namespace std;

class Solution {
    int dp[201][201];
    int minSum(int i,int j, int m,int n, vector<vector<int>>& grid) {
        if(i == m || j == n) return INT_MAX;
        if(dp[i][j] != -1) return dp[i][j];
        return dp[i][j] = (grid[i][j]+min(minSum(i,j+1,m,n,grid),minSum(i+1,j,m,n,grid)));
    }
public:
    int minPathSum(vector<vector<int>>& grid) {
        memset(dp,-1,sizeof(dp));
        int m = grid.size(), n = grid[0].size();
        dp[m-1][n-1] = grid[m-1][n-1];
        return minSum(0,0,m,n,grid);
    }
};