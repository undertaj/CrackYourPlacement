#include <bits/stdc++.h>
using namespace std;

class Solution {
    long long dp[10][26];
    map<int,vector<int>> mp {
        {0,{0,8}},
        {1,{1,2,4}},
        {2,{1,2,3,5}},
        {3,{2,3,6}},
        {4,{1,4,5,7}},
        {5,{2,4,5,6,8}},
        {6,{3,5,6,9}},
        {7,{4,7,8}},
        {8,{0,5,7,8,9}},
        {9,{6,8,9}}
    };
    long long solve(int i, int j) {
        if(dp[i][j] != -1){
           return dp[i][j]; 
        }
        long long res = 0;
        for(int k: mp[i]){
            res = (long long)res+solve(k,j-1);
        }
        return dp[i][j] = res;
    }
  public:
    long long getCount(int n) {
        memset(dp,-1,sizeof(dp));
        for(int i = 0; i < 10; i++){
            dp[i][1] = 1;
        }
        long long sum = 0;
        for(int i = 0; i < 10; i++) {
            sum = (long long)sum+solve(i,n);
        }
        return sum;
    }
};