#include "C.h"

vector<int> findAnagrams(string s, string p) {
    vector<int> res;
    if(p.size()>s.size()) return res;
        unordered_map<char,int> pcm;
        for(auto i:p){
            pcm[i]++;
        }
        int flag=0;
    unordered_map<char,int> scm;
        for(int i=0;i!=p.size();++i)
            scm[s[i]]++;
        if()
    }

    int main(){

    }