
#include "C.h"
using namespace std;
    bool static cmp(vector<int> &p1,vector<int> &p2){
        if(p1[0]==p2[0]) return p1[1]<p2[1];
        else return p1[0]<p2[0];
    }
    bool chuizhi(vector<int> &p1,vector<int> &p2,vector<int> &p3,vector<int> &p4){
        //check(p1,p2) (p3,p4) chuizhi
        int a = p1[0]-p2[0];
        int b = p1[1]-p2[1];
        int c = p3[0]-p4[0];
        int d = p3[1]-p4[1];
        if((a*b+c*d)==0) return true;
        else return false;
    }
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        vector<vector<int> > p;
        p.push_back(p1);
        p.push_back(p2);
        p.push_back(p3);
        p.push_back(p4);
        sort(begin(p),end(p),cmp);

        if((p[0][0]+p[3][0]==p[1][0]+p[2][0])&&(p[0][1]+p[3][1]==p[1][1]+p[2][1])&&chuizhi(p[0],p[3],p[1],p[2])&&chuizhi(p[0],p[1],p[1],p[3])&&(p[3][0]!=p[0][0])) return true;
        else return false;

    }
int main(){
    vector<int> p1={0,0};
    vector<int> p2={0,4};
    vector<int> p3={5,0};
    vector<int> p4={5,4};
    cout<<validSquare(p1,p2,p3,p4)<<endl;
    return 0;
}