#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    //Bubble sort is in place algorithm
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            for(int j = i+1; j < n; j++) {
                if(nums[i] > nums[j])  {
                    int t = nums[i];
                    nums[i] = nums[j];
                    nums[j] = t;
                }   
            }
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
    s.sortColors(v);
    for(int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
}