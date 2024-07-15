#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int j = 0, i = 0, zero = 0;
        for(i = 0; i < nums.size(); i++) {
            if(nums[i] != 0){
                nums[j] = nums[i];
                j++;
            }
            else {
                zero++;
            }
        }
        while(--i && zero){
            nums[i] = 0;
            zero--;
        }
    }
};

int main() {
    Solution s;
    int n;
    cin>>n;
    vector<int> v(n,0);
    for(int i = 0; i < n; i++) {
        cin>>v[i];
    }
    s.moveZeroes(v);
    for(int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
}