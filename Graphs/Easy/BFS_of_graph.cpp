#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        queue<int> q;
        vector<int> vec, vis(V,0);
        q.push(0);
        while(!q.empty()) {
            int x = q.front();
            vis[x] = 1;
            q.pop();
            vec.push_back(x);
            for(int num: adj[x]){
                if(vis[num] == 0){
                    vis[num] = 1;
                    q.push(num);
                }
            }
        }
        return vec;
    }
};