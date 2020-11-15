#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define NULLnum 99

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x): val(x),left(NULL),right(NULL){}
    TreeNode(int x,TreeNode *y): val(x),left(y),right(NULL){}
    TreeNode(int x,TreeNode *y,TreeNode *z):val(x),left(y),right(z){}
};

TreeNode *Tree_init(vector<int> &vec){
    //采用层序遍历,NULL用99代替
    int k=0;
    queue<TreeNode *> qe;
    TreeNode *root=NULL;
    if(vec.size()==0) return NULL;
    if(vec[0]==99) return NULL;

    else{
        root=new TreeNode(vec[0]);
        qe.push(root);
    }
    while(!qe.empty()){
        TreeNode *TN = qe.front();
        qe.pop();
        k++;
        if(k==vec.size()) {cout<<"Wrong! Check your vector"<<endl;return NULL;}
        if(vec[k]!=99){
            TreeNode *TN1=new TreeNode (vec[k]);
            qe.push(TN1);
            TN->left=TN1;
        }
        k++;
        if(k==vec.size()) {cout<<"Wrong! Check your vector"<<endl;return NULL;}
        if(vec[k]!=99){
            TreeNode *TN2=new TreeNode (vec[k]);
            qe.push(TN2);
            TN->right=TN2;
        }
    }
    return root;
}