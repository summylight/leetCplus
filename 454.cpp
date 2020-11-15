#include "C.h"

int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
unordered_map<int,int> mi;
    for(auto i:A){
        for(auto j:B){
            mi[i+j]++;
        }
    }

    mi.clear();
        for(auto i:mi2){
        for(auto j:C){
            mi[j+i.first]+=i.second;
        }
    }
    mi2.clear();
        for(auto i:mi){
        for(auto j:D){
            mi2[j+i.first]+=i.second;
        }
    }
    return mi2[0];
}

int main(){
    vector<int> A={1,2};
    vector<int> B={-2,-1};
    vector<int> C={-1,2};
    vector<int> D={0,2};

    int res = fourSumCount(A,B,C,D);
    cout<<res<<endl;
    return 0;
}