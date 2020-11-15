#include "C.h"
#include <string.h>
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size()) return false;
         int a[26];
        memset(a,0,sizeof(int)*
        26);
        for(auto i:s){
            a[i-'a']++;
        }
        
        for(auto i:t){
            if(--a[i-'a']<0) return false;
        }
        return true;
    }
    int main(){
        string s = "axncxlhjle";
        string t = "xxconlaelh";
        cout << isAnagram(s,t)<<endl;
        return 0;
    }