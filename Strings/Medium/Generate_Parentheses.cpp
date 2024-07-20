#include <bits/stdc++.h>
using namespace std;



class Solution {
public:

    set<string> solve(int ind, vector<set<string>>& dp) {
        if(ind == 1) {
            dp[1].insert("()");
            return dp[1];
        }
        if(!dp[ind].empty()) {
            return dp[ind];
        }
        for(int i = 1; i <= ind/2; i++) {
            int num = ind-i;
            set<string> s1,s2;
            if(!dp[i].empty() && !dp[num].empty()) {
                ;
            }
            else {
                s1 = solve(i, dp);
                s2 = solve(num, dp);
            }
            s1 = dp[i];
            s2 = dp[num];
            for(auto &x : s1) {
                for(auto &y: s2) {
                    dp[ind].insert( x+y);
                    dp[ind].insert( y+x);
                }
            }
        }
        
        set<string> s = solve(ind-1, dp);
        for(auto &x : s) {
            // cout<<ind<<" "<<x<<" = ";
            dp[ind].insert("("+x+")");
            dp[ind].insert(x+"()");
            dp[ind].insert("()"+x);
            // cout<<"("+x+")"<< ", "<< x+"()"<<", "<<"()"+x<<"\n";
        }
        return dp[ind];
    }
    vector<string> generateParenthesis(int n) {
        vector<set<string>> dp(n + 1);
        set<string> se = solve(n, dp);

        return vector<string>(se.begin(), se.end());
    }
};
