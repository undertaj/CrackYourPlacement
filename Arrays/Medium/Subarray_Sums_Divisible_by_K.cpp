#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int count = 0;
        int prefixSum = 0;
        std::unordered_map<int, int> prefixMap;
        prefixMap[0] = 1;

        for (int num : nums) {
            prefixSum += num;
            int mod = prefixSum % k;
            
            if (mod < 0) {
                mod += k;
            }
            if (prefixMap.find(mod) != prefixMap.end()) {
                count += prefixMap[mod];
                prefixMap[mod] += 1;
            } else {
                prefixMap[mod] = 1;
            }
        }
        
        return count;
        
    }
};

int main() {
    Solution s;
    int n, k;
    cin>>n;
    vector<int> v(n,0);
    for(int i = 0; i < n; i++) {
        cin>>v[i];
    }
    cin>>k;
    int count = s.subarraysDivByK(v, k);
    cout<<"Subarrays div by k: "<<count<<"\n";
}