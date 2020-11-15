#include "C.h"

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> prenums(numCourses);
        vector<vector<int> > nextmat(numCourses,vector<int>());
        for(auto i:prerequisites){
            prenums[i[0]]++;
            nextmat[i[1]].push_back(i[0]);
        }
        vector<int> res;
        queue<int> todo;
        for(int i =0;i<numCourses;i++){
            if(!prenums[i]) todo.push(i);
        }
        while(!todo.empty()){
            int i = todo.front();
            res.push_back(todo.front());
            for(auto k:nextmat[i]){
                if(--prenums[k]==0){
                    todo.push(k);
                }
            }
        }
        if(res.size()<numCourses) return vector<int>();
        else return res;
    }

    int main(){
        vector<vector<int>> vvi={{1,0},{2,0},{3,1},{3,2}};
        int n = 4;
        vector<int> f = findOrder(n,vvi);
        return 0;
    }