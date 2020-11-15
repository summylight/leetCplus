#include <vector>
#include <string>
using namespace std;
int maxscore = 0;

void repeat(int pos,int scorenow, vector<vector<int>> &wordsCountlet,vector<int> &letRemain,vector<int> &wordScore){
    int flag=0;
    //fix words[pos] into letremain

    for(int i=0;i!=26;++i){
        letRemain[i]-=wordsCountlet[pos][i];
        if(letRemain[i]<0) flag=1;
    }

    if(flag==0){
        scorenow+=wordScore[pos];
        for(int i=pos+1;i!=wordsCountlet.size();++i){
            repeat(i,scorenow,wordsCountlet,letRemain,wordScore);
        }
    }

    for(int i=0;i!=26;++i)
        letRemain[i]+=wordsCountlet[pos][i];
    if(scorenow>maxscore) maxscore=scorenow;
    return;
}
int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
    vector<vector<int>> wordsCountlet(words.size(),vector<int>(26));
    vector<int> wordScore(words.size());
    for(int i=0;i!=words.size();++i){
        for(int j=0;j!=words[i].size();++j){
            wordsCountlet[i][words[i][j]-'a']++;
            wordScore[i]+=score[words[i][j]-'a'];
        }
    }

    vector<int> letRemain(26,0);
    for(auto i:letters){
        letRemain[i-'a']++;
    }
    int count=0,scorenow=0;
    for(int i=0;i!=words.size();++i)
        repeat(i,scorenow,wordsCountlet,letRemain,wordScore);

    return maxscore;
}

    int main(){
        vector<string> words={"dog","cat","dad","good"};
        vector<char> letters={'a','a','c','d','d','d','g','o','o'};
        vector<int> score={1,0,9,5,0,0,3,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0};

        int res= maxScoreWords(words,letters,score);
        
        return res;
    }