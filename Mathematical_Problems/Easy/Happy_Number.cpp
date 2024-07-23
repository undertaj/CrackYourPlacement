#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isHappy(int n) {
        while(n > 9){
            int a = 0;
            while(n > 0){
                a += (n%10)*(n%10);
                n/=10;
            }
            n = a;
        }
        if(n == 1 || n == 7) return true;
        return false;
    }
};