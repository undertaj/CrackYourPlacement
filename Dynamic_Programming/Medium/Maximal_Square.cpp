#include <bits/stdc++.h>
using namespace std;

class Solution {
    int dp[301][301];
    int solve(int i, int j, int n, int m, vector<vector<char>>& matrix) {
        if(i == n-1 || j == m-1 ||dp[i][j] != -1) {
            return dp[i][j];
        }
        int a = solve(i+1,j,n,m,matrix);
        int b = solve(i,j+1,n,m,matrix);
        if(matrix[i][j] == '1') {
            int c = solve(i+1,j+1,n,m,matrix);
            int ans = 1+ min(a,min(b,c));
            return dp[i][j] = ans;
        }
        return dp[i][j] = matrix[i][j]-'0';
    }
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        memset(dp,-1,sizeof(dp));
        for(int i = 0; i < m; i++){
            dp[n-1][i] = matrix[n-1][i]-'0';
        }
        for(int i = 0; i < n; i++){
            dp[i][m-1] = matrix[i][m-1]-'0';
        }
        int x = solve(0,0,n,m,matrix);
        int res = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                res = max(res,dp[i][j]);
            }
        }
        return res*res;
    }
};