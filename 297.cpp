#include <iostream>
#include <string>
#include <sstream>
#include "TreeNode.h"
using namespace std;
    string serialize(TreeNode* root) {

        string s;
        if(root==NULL) return "[]";
        s+=to_string(root->val);
        s+='[';
        s+=serialize(root->left);
        s+=serialize(root->right);
        s+=']';
        return s;
    }
    TreeNode* des(const string &data,int &pos){
        if(data[pos]=='[')
            //mean NULL
        {
            pos+=2;
            return NULL;
        }
        else{
            int value=0;
            int neg=1;
            if(data[pos]=='-'){
                neg=-1;
                pos++;
            }
            for(;pos!=data.size()&&data[pos]!='[';pos++)
                value=value*10+(data[pos]-'0');
            value= value*neg;
            TreeNode *Node = new TreeNode(value);
            Node->left=des(data,++pos);
            Node->right=des(data,pos);
            ++pos;//']'
            return Node;
        }
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int pos =0;
        TreeNode *root = des(data,pos);
        return root;
    }


    int main(){
        vector<int> vc={1,2,3,99,99,99,99};
        TreeNode *root= initTree(vc);
        string s = serialize(root);
        TreeNode *r = deserialize(s);
        return 0;
    }