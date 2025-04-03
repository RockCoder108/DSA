/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *curr =head;
        ListNode *s=head;
        ListNode *f=head;
        bool value=false;
        while(f!=NULL && f->next!=NULL){
            s=s->next;
            f=f->next->next;
            if(s==f){
                value=true;
                break;
            }
        }
        if(value){
            while(true){
                if(curr==s){
                    return curr;
                }
                curr=curr->next;
                s=s->next;
                
                
            }
        }
        return nullptr;
    }
};