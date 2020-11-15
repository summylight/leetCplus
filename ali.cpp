#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int n,m,c0,d0;
    int a,b,c,d;
    cin >>n>>m>>c0>>d0;
    vector<vector<int> > zongzi(m+1,vector<int>(4,0));
    zongzi[0][2]=c0;
    zongzi[0][3]=d0;
    for(int i=0;i!=m;i++){
        cin>>zongzi[i+1][0]>>zongzi[i+1][1]>>zongzi[i+1][2]>>zongzi[i+1][3];
    }
    vector<pair<double,int> > pervalue;
    for(int i=0;i!=m+1;i++){
        pervalue.push_back(make_pair((((double)zongzi[i][3])/zongzi[i][2]),i+1));
    }
    sort(pervalue.begin(),pervalue.end());
    int resvalue=0;
    for(pair<double,int> tmp : pervalue){
        if(n==0) break;
        int pos;
        pos=tmp.second;
        if(pos==0){
            resvalue+=(n/c0)*d0;
            n=n%c0;
        }
        int size = zongzi[pos][0]/zongzi[pos][1];
        int tmpsize = n/zongzi[pos][2];
        size = min(size , tmpsize);
        resvalue+=size * zongzi[pos][3];
        n=n-zongzi[pos][2]*size;
    }
    return resvalue;
}