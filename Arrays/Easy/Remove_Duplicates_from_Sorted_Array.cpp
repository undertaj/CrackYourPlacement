#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size(), j = 0;
        for(int i = 0; i < n; i++) {
            if(i+1 < n && nums[i] != nums[i+1]){
                nums[j] = nums[i];
                j++;
            }
            else if(i == n-1) {
                nums[j] = nums[i];
                j++;
            }
        }
        return j;
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
    int count = s.removeDuplicates(v);
    cout<<"Unique: "<<count<<"\n";
    for(int i = 0; i < count; i++) {
        cout << v[i] << " ";
    }
}