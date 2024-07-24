#include <bits/stdc++.h>
using namespace std;

class Solution {
    string getString(vector<string> words, int maxWidth, int sum, bool last) {
        int n = words.size();
        string line = "", common = "";
        int c = (maxWidth-sum)%(n==1 ? (maxWidth-sum+1) : (n-1));
        int kk = (maxWidth-sum)/(n==1 ? 1 : (n-1));
        if(last && n != 1) {
            kk = 1;
            c = (maxWidth-sum-n+1);
        }
        while(kk--) common+=" ";
        for(int i = 0; i < n; i++){
            line += words[i];
            if(i != n-1 || n == 1){
                line += common;
            }
            if(c > 0 && n != 1 && !last) {
                line+=" "; 
                c--;
            }
        }
        if(last && n != 1){
            while(c--) line += " ";
        }
        return line;
    }
public:
    //BASIC BRUTE FORCE APPROACH
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int sum = 0, spaces = 0, last_sum = 0;
        string line;
        vector<string> words_list, last_words_list, v;
        for(int i = 0; i < words.size(); i++) {
            int l = words[i].length();
            if(sum+l+spaces >= maxWidth) {
                if(sum+l+spaces == maxWidth){
                    words_list.push_back(words[i]);
                    sum+=l;
                }
                else {
                    i--;
                }
                line = getString(words_list,maxWidth, sum, false);
                v.push_back(line);
                last_words_list = words_list;
                last_sum = sum;
                words_list.clear();
                spaces = 0;
                sum = 0;
            }
            else {
                words_list.push_back(words[i]);
                sum += l;
                spaces++;
            }
        }
        if(words_list.size() > 0){
            line = getString(words_list,maxWidth, sum, false);
            last_words_list = words_list;
            last_sum = sum;
            v.push_back(line);
        }
        line = getString(last_words_list,maxWidth, last_sum, true);
        v.pop_back();
        v.push_back(line);

        return v;
    }
};