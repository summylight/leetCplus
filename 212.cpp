 #include "C.h"

 
    struct TrieNode{
        TrieNode* next[26]={NULL};
        string s;
    };
    
    TrieNode *buildTrie(vector<string> & words){
        TrieNode *root=new TrieNode();
        for(auto word:words){
            TrieNode *p=root;
            for(auto i:word){
                if(!p->next[i-'a'])//non exist
                {
                    TrieNode *tmp= new TrieNode();
                    p->next[i-'a']=tmp;
                }
                p=p->next[i-'a'];
            }
            p->s=word;
        }
        return root;
    }
    void dfs(vector<vector<char>>& board,TrieNode *root,int x , int y,vector<string> &res){
        char c = board[x][y];
        if(c=='#'||!root->next[c-'a']) return;
        TrieNode *p = root->next[c-'a'];
        if(!p->s.empty()){
            res.push_back(p->s);
            p->s.clear();
        }
        
        board[x][y]='#';
        if(x>0) dfs(board,p,x-1,y,res);
        if(y>0) dfs(board,p,x,y-1,res);
        if(x<board.size()-1) dfs(board,p,x+1,y,res);
        if(y<board[0].size()-1) dfs(board,p,x,y+1,res);
        board[x][y]=c;
        return;
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        TrieNode *root= buildTrie(words);
        vector<string> res;
        for(int i=0;i<board.size();i++)
            for(int j=0;j<board[i].size();j++)
                dfs(board,root,i,j,res);
        return res;
    }

    int main(){
        vector<vector<char>> board={{'o','a','a','n'},{'e','t','a','e'},{'i','h','k','r'},{'i','f','l','v'}};
        vector<string> words={"oath","pea","eat","rain"};
        vector<string> res = findWords(board,words);
        return 0;
    }