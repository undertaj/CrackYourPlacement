#include <bits/stdc++.h>
using namespace std;

class Solution {
    int row1[4] = {0,0,-1,1};
    int col1[4] = {1,-1,0,0};
    int row,col;
private: 
    void bfs(int i, int j , vector<vector<int>>& vis,  vector<vector<char>>& grid) {
        // cout<<"bfs("<<i<<")("<<j<<")\n";
        vis[i][j] = 1;
        for(int in =0 ; in < 4; in++) {
            int r = i+row1[in];
            int c = j+col1[in];
            if(r >= 0 && r < row && c >= 0 && c < col && !vis[r][c] && grid[r][c] == '1') {
                bfs(r,c,vis,grid);
            }
        }
        
    }
    void print(vector<vector<int>>& vis) {
        cout<<"Printing vis\n";
        for(int i =0; i < row; i++) {
            for(int j =0 ; j < col; j++) {
                cout<<vis[i][j]<<" ";
            }
            cout<<"\n";
        }

    }
public:
    int numIslands(vector<vector<char>>& grid) {
        row = grid.size(); 
        col = grid[0].size();
        vector<vector<int>> vis(row, vector<int>(col,0));
        int cnt = 0;
        for(int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if(grid[i][j] == '1' && vis[i][j] == 0) {
                    cnt++;
                    bfs(i,j,vis,grid);
                }
                // print(vis);
            }
        }
        return cnt;
    }
};