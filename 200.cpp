
#include <iostream>
#include<vector>
#include <map>
using namespace std;
int sum=0;
    void check(vector<vector<char>>& grid,vector<vector<int>>& island,int i, int j,int flag){
        if(i==0||i==island.size()||j==0||j==island.size()) return ;
        if(grid[i][j]=='0'){
            island[i][j]=0;
            return ;
        }
        else if(island[i][j]==-1){
            // uncheck
            if(flag==0){
                flag=1;
                sum++;
            }
            island[i][j]=sum;
            check(grid,island,i-1,j,flag);
            check(grid,island,i+1,j,flag);
            check(grid,island,i,j-1,flag);
            check(grid,island,i,j+1,flag);
        }
        else return;
    }
    int numIslands(vector<vector<char>>& grid) {
        vector<vector<int>> island(grid.size(),vector<int>(grid.size(),-1));
        //seek island:-1 no check;0 no island;1,2,3...island num
        int size = grid.size();
        for(int i=0;i!=size;++i)
            for(int j=0;j!=size;++j){
                check(grid,island,i,j,0);
            }
        return sum;
    }

int main(){
    vector<int> is;
    map<int ,int > m;
    m.
    is.push_back(0);
    is.push_back(1);
    is.pop_back();
    return 0;
}