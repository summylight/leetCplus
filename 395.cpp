#include "C.h"
#include <set>
    int longestSubstring(string s, int k) {
        if(s.empty()||k>s.size()) return 0;
        if(k<=1) return s.size(); 
        unordered_map<char,int> Map;

        for(auto i:s)
            Map[i]++;

        int index=0;

        while(index<s.size()&&Map[s[index]]>=k) index++;
        if(index==s.size()) return index;

        int left = longestSubstring(s.substr(0,index),k);
        int right = longestSubstring(s.substr(index+1),k);

        return max(left,right);
    }