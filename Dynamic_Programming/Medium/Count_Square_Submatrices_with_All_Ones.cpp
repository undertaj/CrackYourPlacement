#include <bits/stdc++.h>
using namespace std;

class Solution {
    int dp[300][300];
    int solve(int i, int j, vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        if(i == n-1 || j == m-1) {
            return dp[i][j] = matrix[i][j];
        }
        if(dp[i][j] != -1) {
            return dp[i][j];
        }
        int a = solve(i+1,j,matrix);
        int b = solve(i,j+1,matrix);
        int c = solve(i+1,j+1,matrix);
        if(matrix[i][j] == 1){
            return dp[i][j] = 1 + min(a,min(b,c));
        }
        return dp[i][j] = matrix[i][j];
    }
public:
    int countSquares(vector<vector<int>>& matrix) {
        memset(dp,-1,sizeof(dp));
        int val = solve(0,0,matrix);
        int res = 0;
        for(int i = 0; i < matrix.size(); i++) {
            for(int j = 0; j < matrix[0].size(); j++) {
                res += dp[i][j];
            }
        }
        return res;
    }
};