#include <iostream>
using namespace std;
#include <stack>
#include <vector>
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
void rsort(ListNode *head,ListNode *tail){
        ListNode *target  = head->next;
        if(target == tail || target ->next == tail) return;
        ListNode *tmp1 = target;
        ListNode *tmp2;
        while(tmp1->next!=tail){
            if(tmp1->next->val<target->val){
                tmp2 = tmp1->next;
                tmp1->next= tmp1->next->next;
                tmp2->next=head->next;
                head->next= tmp2;
            }
            else tmp1=tmp1->next;
        }
        rsort(head,target);
        rsort(target,tail);
    }
    ListNode* sortList(ListNode* head) {
        ListNode *mhead = new ListNode(0);
        mhead->next = head;
        rsort(mhead,NULL);
        return mhead->next;
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
    vector<int> vc={7,5,3,1,4,8,2};

    ListNode *list= vcTolist(vc);

list = sortList(list);

cout<<"here"<<endl;
}