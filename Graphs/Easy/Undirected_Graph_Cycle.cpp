
#include <bits/stdc++.h>
using namespace std;

class Solution {
    bool cycle(int prev,int i, vector<int> adj[], vector<int> vis){
        if(vis[i] == 1){
            return true;
        }
        vis[i] = 1;
        bool ans = false;
        for(int num: adj[i]){
            if(num != prev) {
                if(vis[num] == 0) {
                    ans = ans || cycle(i,num,adj,vis);
                }
                if(vis[num] == 1){
                    vis[i] = 0;
                    return true;
                }
            }
        }
        vis[i] = 0;
        return ans;
    }
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        vector<int> vis(V,0);
        bool ans = false;
        for(int i = 0; i < V; i++){
            ans = ans || cycle(i,i,adj,vis);
        }
        return ans;
    }
};