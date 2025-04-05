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
    int getlength(ListNode *head){
        int count=1;
        ListNode* curr=head;
        while(curr!=NULL){
            count++;
            curr=curr->next;
        }
        return count;
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int n = getlength(headA);
        int m = getlength(headB);

        while(n > m){
            n--;
            headA=headA->next;
        }

        while(n < m){
            m--;
            headB=headB->next;
        }
        ListNode* temp;
        while(headA!=NULL){
            if(headA==headB){
                temp=headA;
                break;
            }
            headA=headA->next;
            headB=headB->next;
        }
        return temp;
    }
};