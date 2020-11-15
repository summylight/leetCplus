#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int main(){
vector<int> vc={1,2,34};
for(int i=0;i<vc.size();i++){
    cout<<vc[i]<<endl;
    vc.erase(vc.begin()+i);
    i--;
}
return 0;
}