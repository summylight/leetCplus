#include <iostream>
#include <vector>
using namespace std;

 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

ListNode *List_init(vector<int> vec){
    if(vec.size()==0) return NULL;
    ListNode *head =new ListNode(vec[vec.size()-1]);
    for(int i=vec.size()-2;i>=0;i--){
        ListNode *tmp=new ListNode(vec[i],head);
        head=tmp;
    }
    return head;
 }

 void List_print(ListNode *head){
     while(head){
         cout<<head->val<<"\t";
         head=head->next;
     }
     cout<<endl;
 }