

#ifndef _C_
#define _C_
#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
#include <deque>
#include <unordered_map>
#include <map>
#include <vector>
#include "TreeNode.h"
#include "ListNode.h"
#include <math.h>
#include <string>
#include <iomanip>
using namespace std;
template <typename T>
void printVc(const vector<T> &vc){
    //print vector<int> 
    for(auto i:vc) cout<<i<<'\t';
    cout<<endl;
    return;
}
template <typename T>
void printVvc(const vector<vector<T> >  &vvc){
    for(auto i:vvc) {for(auto j:i) cout<<setw(10)<<j;cout<<endl;};
    return;
}
void splitStringbyChar(const string &s,vector<string> &res,const char& delimiter=' '){
    string::size_type last_pos=s.find_first_not_of(delimiter,0);
    string::size_type pos=s.find_first_of(delimiter,last_pos);
    while(string::npos!=pos||string::npos!=last_pos){
        res.emplace_back(s.substr(last_pos,pos-last_pos));
        last_pos=s.find_first_not_of(delimiter,pos);
        pos=s.find_first_of(delimiter,last_pos);
    }
    return ;
}
void splitStringbyString(const string &s,vector<string> &res,const string& delimiters=" "){
    if(delimiters==""){
        cout<<"Delimiters is NULL!"<<endl;
        return;
    }
    string::size_type start = 0;
    auto pos = s.find(delimiters, start);
    while(pos != string::npos) {
        if(pos!=0)
            res.emplace_back(s, start, pos - start);
        start = pos + delimiters.length();
        pos = s.find(delimiters, start);
    }
    if(start < s.length()) // ignore trailing delimiter
        res.emplace_back(s, start, s.length() - start); // add what's left of the string
    return ;
}
#endif