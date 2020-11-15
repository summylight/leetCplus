#include "C.h"
class Node {
public:
    int val;
    vector<Node*> neighbors;
    
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

Node* cloneGraph(Node* node) {
        if(!node) return NULL;
        unordered_map<Node*,Node*> nodemap;
        stack<Node*> nodestack;
        stack<Node*> newstack;
        nodestack.push(node);
        Node* node1=new Node(node->val);
        newstack.push(node1);
        nodemap[node]=node1;
        while(!nodestack.empty()){
            Node *tmp=nodestack.top();
            nodestack.pop();
            Node *newtmp=newstack.top();
            newstack.pop();
            if(!nodemap[tmp])//不存在
            {
                for(int i=0;i<tmp->neighbors.size();i++){
                    Node* nei = tmp->neighbors[i];
                    if(!nodemap[nei]){
                        //不存在的话，赋值，压栈，连接
                        Node *newnei = new Node(nei->val);
                        newtmp->neighbors.push_back(newnei);
                        newnei->neighbors.push_back(newtmp);
                        newstack.push(newnei);
                        nodestack.push(nei);
                    }
                    else{
                        //if exist add vector
                        Node *newnei=nodemap[nei];
                        newtmp->neighbors.push_back(newnei);
                        newnei->neighbors.push_back(newtmp);
                    }
                }
            }
        }
        return node1;
    }

    int main(){
        Node *n1=new Node(1);
        Node *n2=new Node(2);
        Node *n3=new Node(3);
        Node *n4=new Node(4);

        n1->neighbors={n2,n3};
        n2->neighbors={n1,n4};
        n3->neighbors={n1,n4};
        n4->neighbors={n2,n3};

        Node *node = cloneGraph(n1);

        return 0;
    }