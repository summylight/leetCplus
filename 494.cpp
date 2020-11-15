#include "C.h"

    int findTargetSumWays(vector<int>& nums, int S) {
        if(nums.empty()) return 0;
        int sum =0;
        for(auto i:nums)
            sum+=i;
        vector<vector<int>> dp(2,vector<int>(2*sum+1));
        dp[0][sum+nums[0]]=dp[0][sum-nums[0]]=1;
        if(nums[0]==0) dp[0][0]=2;
        int flag=0;
        for(int i=1;i<nums.size();i++){
            flag=1-flag;
            for(int j=0;j<2*sum+1;j++){
                if(j<nums[i])
                    dp[flag][j]=dp[1-flag][j+nums[i]];
                else if (j<2*sum+1-nums[i])
                    dp[flag][j]=dp[1-flag][j+nums[i]]+dp[1-flag][j-nums[i]];
                else dp[flag][j]=dp[1-flag][j-nums[i]];
            }
        }
        return dp[flag][S+sum];
    }

    int main(){
        vector<int> vc(8,0);
        string s ;
        string s1= s.substr(0,)
        int f = findTargetSumWays(vc,0);
        cout<<f<<endl;
        return 0;
    }