#include <vector>
#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;

    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> um;
        for(auto i:nums)
                um[i]++;
        priority_queue<pair<int,int>> pr;
        for(auto i:um){
            pr.push({i.second,i.first});
        }
        vector<int> vi;
       while(k--){
           vi.push_back(pr.top().first);
           pr.pop();
       }
        return vi;
    }

    int main(){
        vector<int> nums={1,1,1,2,2,3,3,3,3,3,4,4,4,4};
        vector<int> res = topKFrequent(nums,3);
        return 0;
    }