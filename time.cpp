#include <iostream>
#include <ctime>
using namespace std;

int main(){
    int x=100;
    clock_t st=clock(),ed;
    for(int i=0;i!=1000000;i++){
     float fx;    
     unsigned long ix, exp; 
        fx = (float)i;  
          ix = *(unsigned long*)&fx;   
           exp = (ix >> 23) & 0xFF;;
    }
    ed=clock();
    cout<<"FLoat cost "<<double(st-ed)/CLOCKS_PER_SEC<<endl;

    st=clock();
    for(int i=0;i!=1000000;i++){
        int nums=0;
        x=i;
        while(x){
            x=x/2;
            nums++;
        }
    }
    ed=clock();
    cout<<"Module cost "<<double(st-ed)/CLOCKS_PER_SEC<<endl;
}