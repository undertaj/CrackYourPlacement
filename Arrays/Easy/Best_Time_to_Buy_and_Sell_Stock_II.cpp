#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size(), r = prices[0], ans = 0;
        for(int i = 0; i < n; i++) {
            if(prices[i] > r){
                ans += prices[i]-r;
                r = prices[i];
            }
            r = min(r,prices[i]);
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
    int profit = s.maxProfit(v);
    cout<<"Max Profit: "<<profit<<"\n";
}