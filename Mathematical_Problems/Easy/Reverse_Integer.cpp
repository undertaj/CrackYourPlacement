#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int reverse(int x1) {
        bool neg = false;
        long long x = x1;
        if(x < 0) {
            x = -x;
            neg = true;
        }
        long long rev = 0;
        while(x > 0) {
            int r = x%10;
            rev = (rev*10) + r;
            x/=10;
        }
        if(rev <= -(long long)pow(2,31) || rev >= ((long long)pow(2,31) - 1))
            return 0;
        return neg ? -rev : rev;
    }
};