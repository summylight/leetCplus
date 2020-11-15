#include<vector>
#include <iostream>
using namespace std;
int rob(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        if(nums.size()==0) return 0;
        vector<int> max(nums.size(),nums[0]);
        max[1]=nums[1];
        if(nums.size()==2) return (nums[0]>nums[1])?nums[0]:nums[1];
        max[2]=nums[2]+nums[0];
        int i;
        for(i=3;i!=nums.size();++i){
            max[i]=((max[i-2]>max[i-3])?max[i-2]:max[i-3])+nums[i];
        }
        return (max[i]>max[i-1])?max[i]:max[i-1];
    }


    int main(){
        vector<int> nums={1,2,3,1};
        int x = rob(nums);
        cout<<x<<endl;
        return 0;
    }