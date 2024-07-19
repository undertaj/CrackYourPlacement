#include <bits/stdc++.h>
using namespace std;


class StockSpanner {
    vector<int> v;
    int l;
public:
    StockSpanner() {
        l = 0;
    }
    
    int next(int price) {
        v.push_back(price);
        l++;
        int coun = 0;
        for(int i = l-1; i >= 0; i--){
            if(v[i] <= price) 
                coun++;
            else 
                break;
        }
        return coun;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */