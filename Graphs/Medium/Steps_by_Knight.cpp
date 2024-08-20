#include <bits/stdc++.h>
using namespace std;


class Solution 
{
    int rr[8] = {2,2,-2,-2,1,-1,1,-1}, cc[8] = {1,-1,1,-1,2,2,-2,-2};
    public:
    //Function to find out minimum steps Knight needs to reach target position.
	int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int N)
	{
	    int vis[N+1][N+1] = {0};
	    queue<pair<int,int>> q;
	    q.push(make_pair(KnightPos[0],KnightPos[1]));
	    int k = -1, n = N;
	    while(!q.empty()) {
	        k++;
	        int ini = q.size();
	        while(ini--) {
	            pair<int,int> x = q.front();
	            q.pop();
    	        if(x.first == TargetPos[0] && x.second == TargetPos[1]){
    	            return k;
    	        }
    	        vis[x.first][x.second] = 1;
    	        for(int k = 0; k < 8; k++) { 
                    int ii = x.first + rr[k];
                    int jj = x.second + cc[k];
                    if(ii >= 1 && ii <= n && jj >= 1 && jj <= n && vis[ii][jj] == 0){
                        vis[ii][jj] = 1;
                        q.push(make_pair(ii,jj));
                    }
                }
	        }
	    }
	    return k;
	}
};