#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& p) {
        int m = p[0], ans  = 0;
        for(int i = 1; i < p.size(); i++) {
            ans = max(ans,p[i]-m);
            m = min(p[i], m);
        }
        return ans;
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
    cout<<s.maxProfit(v)<<"\n";
}