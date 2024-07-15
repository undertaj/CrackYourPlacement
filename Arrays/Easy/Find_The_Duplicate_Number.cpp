#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        vector<int> vec(100000, 0);
        for(int i = 0; i < nums.size(); i++) {
            vec[nums[i]-1]++;
            if(vec[nums[i]-1] > 1) {
                return nums[i];
            }
        }
        return 0;
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
    cout<<s.findDuplicate(v)<<"\n";
}