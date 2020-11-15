#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    int *x = (int *)malloc(10*sizeof(int));
    cout<<sizeof(x)<<endl;
    return 0;
}