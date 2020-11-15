#include "C.h"
    vector<int> repeat(TreeNode* root,const int sum , int &count){
        vector<int> res;
        if(root==NULL) return res;
        vector<int> lres = repeat(root->left,sum,count);
        vector<int> rres = repeat(root->right,sum,count);
        for(auto& i:lres){
            i+=root->val;
            if(i==sum) count++;
        }
        for(auto i:rres){
            i+=root->val;
            if(i==sum) count++;
            lres.push_back(i);
        }
        if(root->val==sum) count++;
        lres.push_back(root->val);
        return lres;
    }
    int pathSum(TreeNode* root, int sum) {
        int count =0;
        vector<int> res= repeat(root,sum,count);
        return count;
    }

int main(){
    vector<int> vi = {10,5,-3,3,2,99,11,3,-2,99,1,99,99,99,99,99,99,99,99};
    TreeNode *root= initTree(vi);
    int count = pathSum(root,8);
    cout<<count<<endl;
    return 0;
}