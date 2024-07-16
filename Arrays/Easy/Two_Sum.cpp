#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int,int>> vec;
        for(int i = 0; i < nums.size(); i++) {
            vec.push_back(make_pair(nums[i],i));
        }
        sort(vec.begin(), vec.end());
        int i = 0,j = 0;
        for( i = 0, j = nums.size()-1; i <j;) {
            if(vec[i].first+vec[j].first > target) {
                j--;
            }
            else if(vec[i].first+vec[j].first < target) {
                i++;
            }
            else {
                return {vec[i].second,vec[j].second};
            }
        }
        return {0,0};
    }
        
    
};

int main() {
    Solution s;
    int n, target;
    cin>>n;
    vector<int> v(n,0);
    for(int i = 0; i < n; i++) {
        cin>>v[i];
    }
    cin>>target;
    vector<int> vv = s.twoSum(v,target);
    for(int i = 0; i < 2; i++) {
        cout << vv[i] << " ";
    }
}