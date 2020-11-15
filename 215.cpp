#include <iostream>
#include <vector>
using namespace std;
int findsort(vector<int> &nums, int low, int high){
    if(low>=high) return low;
    int key = nums[high];
    int begin = low;
    for(int i=low;i!=high;++i){
        if(nums[i]<key)
            swap(nums[i],nums[begin++]);
    }
    swap(nums[begin],nums[high]);
    return begin;
}

int findKthLargest(vector<int>& nums, int k) {
    int low = 0,high = nums.size()-1;
    int pos = findsort(nums,low,high);
    while(pos!=nums.size()-k){
        if(pos<nums.size()-k)
            low=pos+1;
        else high=pos-1;
        pos = findsort(nums,low,high);
    }
    return nums[nums.size()-k];
}

int qsort(vector<int>&nums,int l, int h){
    if(h<=l) return 0;
    int pivort=l;
    int tmp=nums[l];
    int low = l,high=h;
    while(low<high){
        while(nums[high]>tmp&&low<high) high--;
        nums[pivort]=nums[high];
        pivort=high;
        while(nums[low]<tmp&&low<high) low++;
        nums[pivort]=nums[low];
        pivort = low;
    }
    nums[pivort]=tmp;
    qsort(nums,l,pivort-1);
    qsort(nums,pivort+1,h);
    return 1;
}

int main(){
    vector<int> nums={3,5,1,4,9,6,7};
    cout<<findKthLargest(nums,3)<<endl;
    return 1;
}