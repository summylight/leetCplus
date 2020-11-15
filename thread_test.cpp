#include "C.h"

#include <thread>

static int a = 10;
 
void *fun(int k){
    get_new_handler();
    for(int i=0;i<k;i++) ++a;
    cout<<a<<endl;
    int b=3;
     return &b;
}

bool cmp(string &a, string &b){
    return a>b;
}

int main()

    thread a(fun,1000);
    return 0;
}