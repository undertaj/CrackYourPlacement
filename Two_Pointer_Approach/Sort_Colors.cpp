#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        for(int k = 0; k < n; k++) {
            for(int i = 0, j = n-1; i < j; i++,j--) {
                if(nums[i] > nums[i+1])  {
                    int t = nums[i];
                    nums[i] = nums[i+1];
                    nums[i+1] = t;
                }  
                if(nums[j] < nums[j-1])  {
                    int t = nums[j];
                    nums[j] = nums[j-1];
                    nums[j-1] = t;
                }   
            }
        }
    }
};