#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void setZeroes(vector<vector<int>>& m) {
        map<int,int> r,c;
        for(int i = 0; i < m.size(); i++) {
            for(int j = 0; j < m[0].size() ; j++) {
                if(m[i][j] == 0) {
                    r[i] = 1;
                    c[j] = 1;
                }
            }
        }
        for(int i = 0; i < m.size(); i++) {
            for(int j = 0; j < m[0].size() ; j++) {
                if(r[i] || c[j]) {
                    m[i][j] = 0;
                }
            }
        }
    }
};

int main() {
    Solution s;
    int n,m;
    cin>>n>>m;
    vector<vector<int>> v(n, vector<int>(m,0));
    for(int i = 0; i < n; i++) {
        for(int j =0 ; j < m; j++) {
            cin>>v[i][j];
        }
    }
    s.setZeroes(v);
    for(int i = 0; i < v.size(); i++) {
        for(int j = 0; j < v[0].size(); j++) {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
}