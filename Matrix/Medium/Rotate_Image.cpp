#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // void swap()
    void rotate(vector<vector<int>>& m) {
        int n = m.size(), temp;
        int mid = n/2;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(j <= i) {
                    temp = m[i][j];
                    m[i][j] = m[j][i];
                    m[j][i] = temp;
                }
                // swap(m[i][j], m[j][i]);
            }
        }
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n/2; j++) {
                temp = m[i][j];
                m[i][j] = m[i][n-j-1];
                m[i][n-j-1] = temp;
                // swap(m[i][j], m[i][n-j-1]);
            }
        }
    }
};