#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        vector<int> v(n+1,0);
        for(int i = 0; i < n; i++) {
            v[nums[i]] = 1;
        }
        for(int i = 0; i < n+1; i++) {
            if(!v[i]) return i;
        }
        return 0;
    }
};