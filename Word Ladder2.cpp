#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;

void init_neigh(vector<string>& wordList,vector<vector<int>> &neighs){
    int size = wordList.size();
    int wordsize = wordList[0].size();
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            int dif=0;
            for(int k=0;k!=wordsize&&dif<2;k++){
                if(wordList[i][k]!=wordList[j][k])
                    dif++;
            }
            if(dif==1)
                neighs[i].push_back(j);
        }
    }
}

int findpos(string word,vector<string>& wordList){
    for(int i=0;i!=wordList.size();++i)
        if(!word.compare(wordList[i]))
            return i;
    return -1;
}

void repeat(int endpos,int turn, vector<vector<int>> &neighs, vector<int> &flags, queue<vector<int>> &paths){
    if(turn==flags.size()) return;
	int size = paths.size();
	vector<int> tmp;
    int flag=0;
	for (int i = 0; i != size; i++) {
		tmp=paths.front();
        paths.pop();
        for(int k=0;k!=neighs[tmp.back()].size();++k){
            int pos=neighs[tmp.back()][k];
            if(flags[pos]<turn) continue;//visited
            else
            {
                if(pos==endpos) flag=1;
                flags[pos]=turn;
                tmp.push_back(pos);
                paths.push(tmp);
                tmp.pop_back();
            }
        }
	}
    if(!flag) repeat(endpos,turn+1,neighs,flags,paths);
    else return;
}
vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
    vector<vector<string>> res;
    wordList.push_back(beginWord);
    int size = wordList.size();
    vector<vector<int>> neighs(size); // word's neighbors
    vector<int> flags(size,size); //mark word is visited
    init_neigh(wordList,neighs);
    int beginpos = findpos(beginWord,wordList), endpos = findpos(endWord,wordList);
	queue<vector<int>> paths;
	vector<int> tmp(1, beginpos);
	paths.push(tmp);
    flags[beginpos]=0;
    repeat(endpos,1,neighs,flags,paths);
    size = paths.size();
    for(int i=0;i!=size;i++){
        vector<int> tv = paths.front();
        paths.pop();
        if(tv.back()==endpos){
            vector<string> vs;
            for(int j=0;j!=tv.size();++j){
                vs.push_back(wordList[tv[j]]);
            }
            res.push_back(vs);
        }
    }
    return res;
}

int main()
{
    vector<string> wordList = {"hot","dot","dog","lot","log","cog"};
    string s1="hit",s2="cog";
    vector<vector<string>> findLadder=findLadders(s1, s2, wordList);
    return 1;
}