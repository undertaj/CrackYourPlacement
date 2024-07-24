#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<vector<int>, vector<string>> mp;
        vector<vector<string>> v;
        for(int i = 0; i < strs.size(); i++) {
            vector<int> key(26,0);
            for(char c: strs[i]){
                key[c-'a']++;
            }
            mp[key].push_back(strs[i]);
        }
        for(auto e: mp) {
            v.push_back(e.second);
        }
        return v;
    }
};