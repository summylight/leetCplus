#include "C.h"

    bool canPartition(vector<int>& nums) {
        vector<bool> dp(20000,0);
        if(nums.size()==0) return true;
        if(nums.size()==1) return false;
        int sum =0;
        dp[0]=1;
        for(int k=0;k<nums.size()-1;++k){
            int i=nums[k];
            for(int j=0;j<sum+1;j++){
                if(dp[j]) dp[j+i]=1;
            }
            sum+=i;
        }
        int k=nums[nums.size()-1];
        sum+=k;
        for(int i=0;i<sum/2;++i){
            if(dp[i]&&dp[i+k]) return true;
        }
        return false;
    }

    int main(){
        vector<int> vi = {1,2,3,5};
        cout<< canPartition(vi)<<endl;
        return 0;
    }