#include <iostream>
#include "TreeNode.h"
using namespace std;
    void LFS(TreeNode *root,int &a, int &b){
        if(root==NULL){
            a=0;b=0;
            return;
        }
        else {
            int c,d;
            LFS(root->left,c,d);
            int g,f;
            LFS(root->right,g,f);
            c+=g;
            d+=f;
            b=max(c+root->val,d);
            a=d;
            return ;
        }
    }
    int rob(TreeNode* root) {
        int flag=0;
        int a=0,b=0;
        LFS(root,a,b);
        return a;
    }

    int main(){
        vector<int> vc = {3,2,3,99,3,99,1,99,99,99,99};
        TreeNode *root= initTree(vc);
        int m = rob(root);

        cout<<m<<endl;
    }
