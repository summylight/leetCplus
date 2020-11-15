#include <iostream>
#include <vector>
#include <string>
using namespace std;

int check(string s,vector<vector<int> > &dp,int low,int high){
    if(dp[low][high]!=-1) return dp[low][high];
    if(low==high) {
        dp[low][high]=0;
        return 0;
    }
    if(s[low]!=s[high]){
        dp[low][high]=1;
        return 1;
    }
    dp[low][high]=check(s,dp,low+1,high-1);
    return dp[low][high];
}

void repeat(vector<vector<string>> res,string s,vector<vector<int>> dp){
    
}
vector<vector<string>> partition(string s) {
    int len = s.size();

    vector<vector<int> > dp(len,vector<int>(len,-1));//-1 means not check,0 means palindrome, 1 means not palindrome

    for(int i=0;i!=len;++i){
        for(int j=i;j!=len;++j)
            check(s,dp,i,j);
    }

    vector<vector<string>> res;





}