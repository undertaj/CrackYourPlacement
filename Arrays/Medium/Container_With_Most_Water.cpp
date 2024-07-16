#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& h) {
        int i = 0, j = h.size()-1, res = 0;
        while(i < j) {
            int x = min(h[i],h[j]);
            int y = j-i;
            res = max(res,x*y);
            if(h[i] < h[j]) {
                i++;
            }
            else {
                j--;
            }
        }
        return res;
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
    int maxA = s.maxArea(v);
    cout<<"Max Area: "<<maxA<<"\n";
    return 0;
}