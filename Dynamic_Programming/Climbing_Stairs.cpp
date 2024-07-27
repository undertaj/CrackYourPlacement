#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        if(n <= 2)
        return n;
        int p2 = 1, p = 2, c;
        for(int i = 3; i <=n; i++) {
            c = p+p2;
            p2 = p;
            p = c;
        }
        return c;
    }
};