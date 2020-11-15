#include <iostream>
#include <vector>
using namespace std;
struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
void repeat(ListNode *l1,ListNode *l2){
        // fix l1 with the last node of l2
        if(l2->next!=NULL) repeat(l1,l2->next);
        if(l1==l2) {
            l1->next=NULL;
            return;
        }
        ListNode *tmp=l1->next;
        l1->next=l2;
        l2->next=tmp;
        l1=tmp;
    }
    void reorderList(ListNode* head) {
        ListNode *l1=head,*l2=head;
        
        while(l1->next!=NULL&&l2->next!=NULL){
            l1=l1->next;
            l2=l2->next;
            if(l2->next==NULL) break;
            else l2=l2->next;
        }
        
        repeat(head,l1);
    }

    int main(){
        vector<ListNode> list(5,ListNode(4));

        for(int i =0;i<4;i++){
            list[i].next=&list[i+1];
            list[i].val=i;
        }

        reorderList(&list[0]);

        return 0;
    }