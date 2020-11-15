#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int get(string a,string b){
    int size = a.size();
    int count = 0;
    int acount=0,bcount=0;
    for(int i=0;i!=size;i++){
        if(a[i]!=b[i]) count++;
        if(a[i]=='1') acount++;
        if(b[i]=='1') bcount++;
    }

    int cha = abs(acount-bcount);
    return (cha-count)/2+count;
}
int main(){
    int lens;
    string a , b;
    cin>>lens>>a>>b;

    int tmp = get(a,b);
    reverse(a.begin(),a.end());

    cout<< min(tmp,get(a,b))<<endl;

    return 0;

}

