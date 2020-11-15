#include "C.h"

int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    if(wordList.empty()) return 0;
    unordered_map<string,vector<string> > svm;
    wordList.push_back(beginWord);
    int wordlen=wordList[0].size();
    int wordnum=wordList.size();
    for(auto i : wordList){
        string tmpi=i;
        for(int k=0;k<wordlen;k++){
            char c = i[k];
            i[k]='*';
            svm[i].push_back(tmpi);
            i[k]=c;
        }
    } 
    int res=1;
    queue<string> todo;
    todo.push(beginWord);
    map<string,bool> visited;
    visited[beginWord]=1;
    int ladder=1;

    while(!todo.empty()){
        int n = todo.size();
        for(int j=0;j<n;j++){
            string i= todo.front();
            todo.pop();
            for(int k=0;k<wordlen;k++){
                char c = i[k];
                i[k]='*';
                for(auto word:svm[i]){
                    if(word==endWord) return ladder;
                    if(!visited[word]){
                        //unvisited
                        visited[word]=1;
                        todo.push(word);
                    }
                }
                i[k]=c;
            }
        }
        ladder++;
    }
    return 0;
}