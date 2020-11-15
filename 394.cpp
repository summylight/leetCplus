#include <iostream>
#include <string>
#include <stack>
#include <algorithm>
using namespace std;
stack<int> si;

string decodeString(string s) {
    stack<int> si;
    stack<char> sc;

    for(int i=0;i<s.size();++i){
        if(isdigit(s[i])){
            int val=0;
            while(isdigit(s[i])){
                val=val*10+s[i]-'0';
                i++;
            }
            --i;
            si.push(val);
        }
        else if(s[i]==']'){
            string s1;
            while(sc.top()!='['){
                s1+=sc.top();
                sc.pop();
            }

            reverse(s1.begin(),s1.end());
            sc.pop();

            int d=si.top();
            si.pop();
            for(int i=0;i<d;++i){
                for(int j=0;j<s1.size();++j)
                    sc.push(s1[j]);
            }
        }
        else sc.push(s[i]);
    }

    string res;
    while(!sc.empty()){
        res+=sc.top();
        sc.pop();
    }
    reverse(res.begin(),res.end());
    return res;
}

    int main(){
        string s="5[2[ab]4[c]]";
        string de = decodeString(s);
        cout<<de<<endl;
    }