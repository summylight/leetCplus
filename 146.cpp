#include <iostream>
using namespace std;

class LRUCache {
public:
    int cap;
    int size;
    struct Node{
        int key;
        int value;
        Node* next;
        Node(int k,int v) : key(k),value(v),next(NULL){}
    };
    Node *end;
    Node *head;
    LRUCache(int capacity) {
        cap = capacity;
        size=0;
        head = new Node(0,0);
        end=head;
    }
    
    int get(int key) {
        Node *pos= head;
        while(pos->next!=NULL){
            if(pos->next->key == key) {
                Node *tmp=pos->next;
                end->next= tmp;
                pos->next=pos->next->next;
                tmp->next=NULL;
                end = tmp;
                cout<<tmp->value<<endl;
                return tmp->value;
            }
            pos=pos->next;
        }
        cout<<"-1"<<endl;
        return -1;
    }
    
    void put(int key, int value) {
        Node *pos= head;
        while(pos->next!=NULL){
            if(pos->next->key == key) {
                Node *tmp=pos->next;
                pos->next=pos->next->next;
                end->next= tmp;
                tmp->next=NULL;
                tmp->value = value;
                return;
            }
            pos=pos->next;
        }
        if(size<cap){
            Node *tmp = new Node(key,value);
            end->next= tmp;
            end = tmp;
            size++;
        }
        else{
            Node *tmp2 = new Node(key,value);
            end->next= tmp2;
            end = tmp2;
            head->next=head->next->next;
        }
        return ;
    }
};

int main(){
    LRUCache *cache = new LRUCache(1);
    cache->put(2, 1);
    cache->get(2);       // returns 1
    cache->put(3, 2);    // evicts key 2
    cache->get(2);       // returns -1 (not found)
    cache->get(3);       // returns 3
    cache->get(4);       // returns 4
    return 0;
}