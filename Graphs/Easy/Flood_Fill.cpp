#include <bits/stdc++.h>
using namespace std;

class Solution {
int row1[4] = {-1,1,0,0};
int col1[4] = {0,0,1,-1};
int n,m;
private: 
    void dfs(vector<vector<int>>& image, int sr, int sc, int color, vector<vector<int>>& vis) {

        int val = image[sr][sc];
        image[sr][sc] = color;
        vis[sr][sc] = 1;
        for(int i =0; i < 4; i++) {
            int r = sr+row1[i];
            int c = sc+col1[i];
            if(r >= 0 && r < n && c >= 0 && c < m && image[r][c] == val && !vis[r][c]) {
                // cout<<"("<<sr<<")("<<sc<<") -> ("<<r<<")("<<c<<")\n";
                dfs(image,r,c,color, vis);
            }
        }
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        vector<vector<int>> im = image;
        n = image.size();
        m = image[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        dfs(im,sr,sc, color, vis);
        return im;
    }
};