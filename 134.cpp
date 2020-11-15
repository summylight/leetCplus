#include <iostream>
using namespace std;
#include <stack>
#include <vector>
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

void reorderList(ListNode* head) {
    if(head == NULL || head->next == NULL) return ;
    stack<ListNode*> list;
    ListNode *tmp=head;
    while(tmp!=NULL){
        list.push(tmp);
        tmp=tmp->next;
    }
    ListNode *pos=head;
    while(pos!=list.top()&&pos->next!=list.top()){
        tmp=pos->next;
        pos->next=list.top();
        list.pop();
        pos->next->next=tmp;
        pos=tmp;
    }
    list.top()->next=NULL;
    return;
}

ListNode *vcTolist(vector<int> vc){
    int size = vc.size();
    ListNode *head = new ListNode(vc[0]);
    ListNode *tmp1=head;
    for(int i=1;i!=size;i++){
        ListNode *tmp2 = new ListNode(vc[i]);
        tmp1->next= tmp2;
        tmp1=tmp2;
    }
    tmp1->next= NULL;
    return head;
}
int main(){
    vector<int> vc={1,2,3};

    ListNode *list= vcTolist(vc);

reorderList(list);

cout<<"here"<<endl;
}