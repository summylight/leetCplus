#include <iostream>
#include <vector>
#include <algorithm>
#include "C.h"
using namespace std;
    double Power(double base, int exponent) {
        vector<double> vd;
        double res=1.0;
        vd.push_back(base);
                    if(exponent%2==1) res*=base;
        int tmp=exponent>>1;
        while(tmp){

            vd.push_back(vd[vd.size()-1]*vd[vd.size()-1]);
            if(tmp%2==1) res*= vd[vd.size()-1];
            tmp=tmp>>1;
        }
        return res;
    }
    int main(){
        cout<<Power(2,3)<<endl;
        return 0;
    }