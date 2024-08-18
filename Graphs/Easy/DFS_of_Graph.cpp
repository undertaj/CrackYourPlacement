#include <bits/stdc++.h>
using namespace std;

class Solution {
    vector<int> vec;
    void dfs(int i, vector<int> adj[], vector<int>& vis) {
        vis[i] = 1;
        vec.push_back(i);
        for(int num : adj[i]){
            if(vis[num] == 0){
                dfs(num,adj,vis);
            }
        }
    }
  public:
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        vector<int> vis(V,0);
        dfs(0,adj,vis);
        return vec;
    }
};