#include <bits/stdc++.h>
using namespace std;

class Solution {
    int rr[4] = {-1,1,0,0}, col[4] = {0,0,-1,1};//L D U R
    char c[4] = {'U','D','L','R'};
    vector<string> paths;
    void dfs(int i, int j, vector<vector<int>>& vis, vector<vector<int>>& mat, string s){
        int n = mat.size();
        if(i == n-1 && j == n-1){
            paths.push_back(s);
            return;
        }
        vis[i][j] = 1;
        for(int k = 0; k < 4; k++){
            int ii = i + rr[k];
            int jj = j + col[k];
            if(ii >= 0 && ii < n && jj >= 0 && jj < n && mat[ii][jj] == 1 && vis[ii][jj] == 0) {
                dfs(ii,jj,vis,mat, s+c[k]);
            }
        }
        vis[i][j] = 0;
    }
    
  public:
    vector<string> findPath(vector<vector<int>> &mat) {
        // Your code goes here
        vector<vector<int>> vis(mat.size(), vector<int>(mat.size(),0));
        if(mat[0][0] == 0) return {};
        dfs(0,0,vis,mat,"");
        return paths;
    }
};