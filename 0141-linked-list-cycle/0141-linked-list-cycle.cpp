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
    bool hasCycle(ListNode* head) {
        // if (head == NULL || head->next == NULL)
        //     return false;
        // ListNode* curr = head;
        // ListNode* s = curr;
        // ListNode* f = curr;

        // while (f!= NULL && f->next != NULL) {
        //     s = s->next;
        //     f = f->next->next;
        //     if (s == f) {
        //         return true;
        //     }
        // }
        // return false;


        ListNode* s=head;
        ListNode* f=head;
        while(f!=NULL && f->next!=NULL){
            s=s->next;
            f=f->next->next;
            if(s==f){
                return true;
            }
            
        }
        return false;
    }
};