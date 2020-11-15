#include <stack>
#include <iostream>
#include <vector>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
    vector<int> preorderTraversal(TreeNode* root) {
        stack<TreeNode *> st1;
        stack<TreeNode *> st2;
        vector<int> res(0);
        if(root==NULL) return res;
        st1.push(root);
        while(!st1.empty()){
            TreeNode *tmp = st1.top();
            st1.pop();
            if(tmp->left!=NULL) st1.push(tmp->left);
            if(tmp->right!=NULL) st1.push(tmp->right);
            st2.push(tmp);
        }
        while(!st2.empty()){
            res.push_back(st2.top()->val);
            st2.pop();
        }
        return res;
    }