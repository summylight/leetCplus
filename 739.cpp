#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> dailyTemperatures(vector<int>& T) {
        stack<int> dp;
        vector<int> res(T.size(),0);
        for(int i=0;i!=T.size();++i){
            if(dp.empty()) dp.push(i);
            else{
                if(T[dp.top()]>=T[i]) dp.push(i);
                else{
                    do{
                        res[dp.top()]=i-dp.top();
                        dp.pop();
                    }while(!dp.empty()&&T[dp.top()]<T[i]);
                    dp.push(i);
                }
            }
        }

        return res;
    }

    int main(){
        vector<int> T = {73,74,75,71,69,72,76,73};
        vector<int> res = dailyTemperatures(T);
        return 0;
    }