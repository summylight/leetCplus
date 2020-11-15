#include <iostream>
#include <vector>
using namespace std;
int longestConsecutive(vector<int>& nums) {
    vector<int> pos(2100,0),neg(2100,0);
    int a,b,c=1;
    for(auto i:nums){
        if(i>=0){
            a=i/32;
            b=i%32;
            c=c<<b;
            pos[a]=pos[a]|c;
        }
        else{
            i=-(i+1);
            a=i/32;
            b=i%32;
            c=c<<b;
            neg[a]=neg[a]|c;
        }
        c=1;
    }

    int max_len=0,flag=0,len=0;
    for(int i=neg.size()-1;i>=0;i--){
        c=1<<31;
        for(int j =32;j>0;j--){
            if(neg[i]&c){
                len++;
            } 
            else{
                if(len>max_len) max_len=len;
                len=0;
            }
        c=c>>1;
        }
    }
    for(int i=0;i<pos.size();i++){
        c=1;
        for(int j =0;j<32;j++){
            if(pos[i]&c){
                len++;
            } 
            else{
                if(len>max_len) max_len=len;
                len=0;
            }
            c=c<<1;
        }
    }
    return max_len;
}


int main(){
    vector<int> nums={100,4,200,3,2,1,0,-1};

    cout<< longestConsecutive(nums)<<endl;
    return 0;
}