#include <iostream>
#include <vector>
using namespace std;
int main(){
    vector<int> n = {2,3,-2,4};
    int i = maxProduct(n);
    return i;
}

int maxProduct(vector<int>& nums) {
    if(nums.size()==1) return nums[0];
        int max=0;
        int pos=0,neg=0;
        for(auto i:nums){
            if(i>0){
                if(pos==0) pos=1;
                pos=pos*i;
                neg=neg*i;
            }
            else if(i==0){
                pos=0;
                neg=0;
            }
            else {
                int tmp = pos;
                pos = neg * i ;
                if(tmp==0) neg = i;
                else neg = tmp * i;
            }
            max = (max>pos)?max:pos;
        }
        return max;
    }