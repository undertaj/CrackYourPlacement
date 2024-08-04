#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int trap(vector<int>& h) {
        vector<int> hmax(h.size()), hmin(h.size());
        
        hmax[0] = h[0];
        for(int i = 1; i < h.size(); i++) 
            hmax[i] = (hmax[i-1] > h[i]) ? hmax[i-1] : h[i];
        
        hmin[h.size()-1] = h[h.size()-1];
        for(int i = h.size()-2; i >= 0; i--) 
            hmin[i] = (hmin[i+1] > h[i]) ? hmin[i+1] : h[i];   
        
        int ans = 0;
        for(int i = 1; i < h.size()-1; i++) {
            int x = min(hmin[i], hmax[i]);
            ans += x-h[i];
        }
        return ans;
    }
};