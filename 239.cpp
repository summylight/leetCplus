#include <iostream>
#include <vector>
#include <deque>
using namespace std;
    vector<int> maxSlidingWindow1(vector<int>& nums, int k) {
        //立住一个中间值，发现只要比对之前的a个值和后续的k-a-1个值，这些值是可以DP的
        //设置中间值为k-1,2k-1,3k-1....
        //查询范围为(0,2k-2),(k,3k-2),(2k,4k-2)
        int size = nums.size();
        int t = size/k;
        vector<int> store(size,0);
        for(int i=1;i!=t;++i){
            //对于每个中间值做操作
            int pos = i*k-1;
            store[pos] = nums[pos];
            for(int j=1;j!=k;j++){
                store[pos-j]=max(store[pos-j+1],nums[pos-j]);
                store[pos+j]=max(store[pos+j-1],nums[pos+j]);
            }
            for(int j=1;j!=k-1;j++)
                store[pos-j]=max(store[pos-j],store[pos-j+k-1]);
            store[pos]=store[pos+k-1];
        }
        //对最后一个中间值做操作
            int pos = t*k-1;
            store[pos] = nums[pos];
            for(int j=1;j!=k;j++){
                store[pos-j]=max(store[pos-j+1],nums[pos-j]);
                if(pos+j<size) store[pos+j]=max(store[pos+j-1],nums[pos+j]);
            }
            for(int j=pos-k+2;j!=size-k+1;j++)
                store[j]=max(store[j],store[j+k-1]);
        vector<int> res;
        for(int i=0;i!=size-k+1;i++)
            res.push_back(store[i]);
        return res;
    }

    vector<int> maxSlidingWindow2(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> ans;
        for (int i=0; i<nums.size(); i++) {
            if (!dq.empty() && dq.front() == i-k) dq.pop_front();
            while (!dq.empty() && nums[dq.back()] < nums[i])
                dq.pop_back();
            dq.push_back(i);
            if (i>=k-1) ans.push_back(nums[dq.front()]);
        }
        return ans;
    }
    int main(){
        vector<int> nums={1,3,-1,-3,5,3,6,7};
        vector<int> res= maxSlidingWindow2(nums,3);
        for(auto i:res)
            cout<<i<<endl;
        return 0;
    }