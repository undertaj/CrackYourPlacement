#include <bits/stdc++.h>
using namespace std;

class Solution {
    //USED PAIR MAP AS DP DATA SINCE THE VALUE WAS LARGE FOR STATIC DP
    map<pair<int,int>,bool> t;
    set<int> set;
    int last;
    bool frogJump(int curr, int n){
        if(t.find(make_pair(curr,n)) != t.end()) 
            return t[make_pair(curr,n)];
        if(curr == 0){
            if(set.find(curr+n) != set.end()) 
            return t[make_pair(curr,n)] = frogJump(curr+n,n);
            else return t[make_pair(curr,n)] = false;
        }
        if(curr == last) return t[make_pair(curr,n)] = true;
        bool x = false;
        if(n-1 >= 1 && set.find(curr+n-1) != set.end()){
            x = x || frogJump(curr+n-1,n-1);
        }
        if(x) return t[make_pair(curr,n)] = x;
        if(set.find(curr+n) != set.end()) {
            x = x || frogJump(curr+n,n);
        }
        if(x) return t[make_pair(curr,n)] = x;
        if(set.find(curr+n+1) != set.end()) {
            x = x || frogJump(curr+n+1,n+1);
        }
        return t[make_pair(curr,n)] = x;
    }
public:
    bool canCross(vector<int>& stones) {
        for(int i= 0; i < stones.size(); i++){
            set.insert(stones[i]);
            last = stones[i];
        }
        return frogJump(0,1);
    }
};