   #include <iostream>
#include <vector>
using namespace std;

   
    struct Node{
        char val;
        vector<Node*> nodemap;
        bool end=false;
        Node(char x):
            val(x),nodemap(vector<Node*>(23,NULL)){}
    };
    Node *head;
    /** Initialize your data structure here. */
    /** Inserts a word into the trie. */
    void insert(string word) {
        Node *tmp,*pre=head;
        for(int i=0;i!=word.size();++i){
            if(!pre->nodemap[word[i]-'a']){
            tmp=new Node(word[i]);
            pre->nodemap[word[i]-'a']=tmp;
            pre=tmp;
            }
            else pre=pre->nodemap[word[i]-'a'];
        }
        pre->end=true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        Node *tmp=head;
        for(int i=0;i!=word.size();++i){
            if(!tmp->nodemap[word[i]-'a']) return false;
            else{
                tmp=tmp->nodemap[word[i]-'a'];
            }
        }
        return tmp->end;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
                Node *tmp=head;
        for(int i=0;i!=prefix.size();++i){
            if(!tmp->nodemap[prefix[i]-'a']) return false;
            else{
                tmp=tmp->nodemap[prefix[i]-'a'];
            }
        }
        return true;
    }
    int main(){
        head = new Node('0');
        insert("pref");
        insert("prefi");
        insert("prefix");
        return 0;
    }