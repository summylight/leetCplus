#include <iostream>
#include <vector>
using namespace std;

    int coinChange(vector<int>& coins, int amount) {
        if(coins.size()==0) return -1;
        vector<int> dp(amount+1,INT_MAX);
        dp[0]=0;
        for(int i=1;i!=amount+1;++i){
            for(int j=0;j!=coins.size();++j){
                if(i-coins[j]<0||dp[i-coins[j]]==INT_MAX) continue;
                else{
                    dp[i]=min(dp[i],dp[i-coins[j]]+1);
                }
            }
        }
        if(dp[amount+1]==INT_MAX) return -1;
        else return dp[amount+1];
    }

    int main(){
        vector<int> coins={1,2,5};
        int amount = 11;
        int c=coinChange(coins,amount);
        cout<<c<<endl;
        return 0;
    }