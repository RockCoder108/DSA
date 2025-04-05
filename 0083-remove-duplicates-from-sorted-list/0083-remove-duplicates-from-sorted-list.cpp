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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL || head->next==NULL){
            return head;
        }
        ListNode* curr=head;
        ListNode* temp=nullptr;
        while(curr!=NULL && curr->next!=NULL){
            temp = curr;
            curr =curr->next;
            if(temp->val == curr->val){
                temp->next=curr->next;
                ListNode* temp1=curr;
                curr=curr->next;
                delete temp1;
            }

        }
        return head;
    }
};