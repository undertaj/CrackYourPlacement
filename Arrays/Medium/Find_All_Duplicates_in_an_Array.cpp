#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> vec(100000, 0), a;
        for(int &i : nums){
            vec[i-1]++;
            if(vec[i-1] == 2) a.push_back(i);
        }
        return a;
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
    vector<int> ans = s.findDuplicates(v);
    for(int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
}