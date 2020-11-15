#include "C.h"
#include <sstream>
    bool comp(char a,char b){
        if(a=='*'||a=='/') return true;
        else if(b=='+'||b=='-') return true;
           else return false;
    }
    
    int cal(int a,int b, char op){
        switch(op){
            case '+':
                return a+b;
                break;
            case '-':
                return a-b;
                break;
            case '*':
                return a*b;
                break;
            case '/':
                return a/b;
        }
        return 0;
    }
    int calculate(string s) {
        int a,b;
        istringstream st(s);
        char preop;
        char nowop;
        if(!(st>>a)) return 0;
        if(!(st>>preop)) return a;
        st>>b;
        while(st>>nowop){
            if(comp(preop,nowop)){
                //calculate preop
                a=cal(a,b,preop);
                preop=nowop;
                st>>b;
            }
            else{
                //calculate nowop
                int tmp;
                st>>tmp;
                b=cal(b,tmp,nowop);
            }
        }
        return cal(a,b,preop);
        
    }