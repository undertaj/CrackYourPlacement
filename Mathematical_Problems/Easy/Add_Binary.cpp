#include <bits/stdc++.h>
using namespace std;

class Solution {
    
public:
    string addBinary(string a, string b) {
        map<string,int> mp = 
        {
            {"000",0},
            {"001",1},
            {"010",1},
            {"011",10}, 
            {"100",1},
            {"101",10},
            {"110",10},
            {"111",11}
        };
        int i = a.length()-1, j = b.length()-1;
        string s = "0", ans = "";
        while(i > -1 || j > -1 ){
            if(i <= -1 && j <= -1){
                break;
            }
            if(i <= -1) s += "0";
            else s += a[i];
            if(j <= -1) s += "0";
            else s += b[j];
            for(auto e: mp){
                if(e.first == s){
                    if(e.second%10) ans = "1"+ans;
                    else ans = "0"+ans;
                    if(e.second < 2) s = "0";
                    else s = "1";
                    break;
                }
            }
            i--;
            j--;
        }
        if(s == "1"){
            ans = "1"+ans;
        }
        return ans;
    }
};