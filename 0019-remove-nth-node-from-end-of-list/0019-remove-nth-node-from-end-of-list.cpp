/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head==nullptr || head->next==nullptr){
            delete head;
            return NULL;
        }
        ListNode* slow=head;
        ListNode* fast=head;
        int count=0;
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
            count++;
        }
        if(fast==nullptr){
            count = count+count;
        }else{
            count = count+count+1;
        }
        count = count-n;
        if(count<=0){
            ListNode* temp2=head;
            head = head->next;
            delete temp2;
            return head;
        }
        
        ListNode* curr=head;
        if(count==1){
            if(head->next->next==NULL){
                ListNode* temp1=head->next;
                head->next = NULL;
                delete temp1;
                return head;
            }
        }
        count--;
        while(count){
            curr=curr->next;
            count--;
        } 
        ListNode* temp=curr->next;
        curr->next= curr->next->next;
        delete temp;

        return head;
        
    }
};