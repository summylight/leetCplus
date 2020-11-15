#include <iostream>
#include <vector>
#define min(x,y) ((x)>(y))?(y):(x)
#define max(x,y) ((x)>(y))?(x):(y)
using namespace std;

    int maximalSquare(vector<vector<char>>& matrix) {
        int xsize = matrix.size();
        if(xsize==0) return 0;
        int ysize = matrix[0].size();
        int maxsize = 0;
        int tmp,pre;
        vector<int> vec(ysize,0);
        for(int i=0;i!=xsize;++i)
            for(int j=0;j!=ysize;++j){
                if(!i||!j||matrix[i][j]=='0'){
                    pre = vec[j];
                    vec[j]=matrix[i][j]-'0';

                }
                else{
                    tmp = vec[j];
                    vec[j]=min(min(vec[j-1],pre),vec[j])+1;
                    pre = tmp;
                }
                maxsize = max(maxsize,vec[j]);
            }
        return maxsize*maxsize;
    }

    int main(){
        vector<vector<char> > mat ={{'1
        ','0','1','0','0'},{'1','0','1','1','1'},{'1','1','1','1','1'},{'1','0','0','1','0'}};
        int t = min(min(1,1),0)+1;
        int s= maximalSquare(mat);
        return 0;
    }