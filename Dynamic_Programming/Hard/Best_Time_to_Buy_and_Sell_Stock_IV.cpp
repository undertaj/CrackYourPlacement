#include <bits/stdc++.h>
using namespace std;

class Solution {
    int dp[1001][101][2];
    int solve(int buy, int index,int k, vector<int>& prices) {
        if(index >= prices.size() || k == 0){
            return 0;
        }
        int check = 1;
        if(buy == 1001) check = 0;
        if(dp[index][k][check] != -1) {
            return dp[index][k][check];
        }
        if(buy == 1001) {
            int bought = -prices[index]+solve(prices[index], index+1,k,prices);
            int b = solve(buy,index+1,k,prices);
            return dp[index][k][check] = max(bought,b);
        }
        int sell = prices[index] + solve(1001, index+1,k-1,prices);
        int c = solve(buy,index+1,k,prices);
        return dp[index][k][check] = max(sell,c);
    }
public:
    int maxProfit(int k, vector<int>& prices) {
        memset(dp,-1,sizeof(dp));
        return solve(1001,0,k,prices);
    }
};