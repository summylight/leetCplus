
#include "TreeNode.h"
TreeNode *minroot=NULL;
    int Seek(TreeNode *root, int p,int q){
        if(root==NULL) return 0;
        int leftseek,rightseek;
        if((leftseek=Seek(root->left,p,q))==3) return 3;
        else if((rightseek = Seek(root->right,p,qt))==3) return 3;

        if(root->val==p) leftseek +=1;
        else if(root->val==q) leftseek +=2;
        if((leftseek+rightseek)==3){
            minroot=root;
            
            return 3;
        }
        else return leftseek+rightseek;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, int p, int  q) {
 
        Seek(root,p,q);
        return minroot;
    }
    

    int *t(int *&a){
        int *b= new int(3);
        a=b;
        return 0;        

    }


    int main(){
        vector<int> vec={3,5,1,6,2,0,8,99,99,7,4,99,99,99,99,99,99,99,99};
        int a =4;
        int *b=&a;
        t(b);

        TreeNode *root = initTree(vec);
        TreeNode *res = lowestCommonAncestor(root,5,1);
        cout<< res->val<<endl;
        return 0;
    }