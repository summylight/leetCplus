#include "ListNode.h"
 
    bool isPalindrome(ListNode* head) {
        if(head==NULL||head->next==NULL) return true;
        ListNode *tmphead=new ListNode(0,head);
        ListNode *pre=tmphead,*pos=tmphead;
        while(pos!=NULL&&pos->next != NULL){
            pre= pre->next;
            pos=pos->next->next;
        }

        while(pre->next!=NULL){
            pos=tmphead->next;
            tmphead->next=pre->next;
            pre->next=pre->next->next;
            tmphead->next->next=pos;
            PrintList(tmphead);
        }
        
        //check palindrome
        pre=head;
        pos=tmphead->next;
        while(pre!=head&&pos!=NULL){
            if(pre->val!=pos->val)  return false;
            else{
                pre=pre->next;
                pos=pos->next;
            }
        }
        return true;
    }

int main(){
    vector<int> Listval={1,2};
    ListNode *head = ConvertValIntoList(Listval);

    bool res = isPalindrome(head);
    std::cout<<res<<std::endl;
    return res;
}