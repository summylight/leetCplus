#include<iostream>
#include <stack>
#include <string>

using namespace std;
    void stringtostack(string s, stack<string> &st, int low, int high){
        if(low==high) return;
        else{
            string a=s.substr(low,high-low);
            st.push(a);
        }
    }
    
    void pu(string &res, string s){
        for(int i=0;i!=s.size();++i){
            res.push_back(s[i]);
        }
        return;
}
    string reverseWords(string s) {
        int blankflag=1;
        int charflag=1;
        stack<string> st;
        int low=0,high=0;
        for(int i=0;i!=s.size();++i){
            if(s[i]!=' '){
                if(charflag==1){
                    low=i;
                    high=i+1;
                    charflag=0;
                }
                else{
                    high++;
                }
            }
            else{
                stringtostack(s,st,low,high);
                low=i;
                high=i;
                charflag=1;
            }
        }
        stringtostack(s,st,low,high);
        string res;
        int size = 0;
        if(st.empty()) return res;
        pu(res,st.top());
        st.pop();
        while(!st.empty()){
            res.push_back(' ');
            pu(res,st.top());
            st.pop();
        }
        return res;
    }
int main(){
    string a="a good   example";
    string b=reverseWords(a);
    cout<<b<<endl;
    return 0;
}