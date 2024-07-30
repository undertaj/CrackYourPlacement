#include <bits/stdc++.h>
using namespace std;

class Solution {
    int dp[2501];
    int longest(int i,vector<int>& nums) {
        if(dp[i] != -1) 
            return dp[i];
        int m = 0;
        for(int j = i+1; j < nums.size(); j++) {
            int k = longest(j,nums);
            if(nums[j] > nums[i]) {
                m = max(m,longest(j,nums));
            }
        }
        return dp[i] = 1+m;
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        int m = max(m,longest(0,nums));
        return *max_element(dp, dp+nums.size());
    }
};