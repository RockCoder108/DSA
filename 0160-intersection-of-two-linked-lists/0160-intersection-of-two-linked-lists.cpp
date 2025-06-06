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
    // int getlength(ListNode *head){
    //     int count=1;
    //     ListNode* curr=head;
    //     while(curr!=NULL){
    //         count++;
    //         curr=curr->next;
    //     }
    //     return count;
    // }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        // int n;
        // int count=1;
        // ListNode* curr=headA;
        // while(curr!=NULL){
        //     count++;
        //     curr=curr->next;
        // }
        // n=count;
        // int m;
        // int counts=1;
        // ListNode* currs=headB;
        // while(currs!=NULL){
        //     counts++;
        //     currs=currs->next;
        // }
        // m=counts;
        
        // while(n > m){
        //     n--;
        //     headA=headA->next;
        // }

        // while(n < m){
        //     m--;
        //     headB=headB->next;
        // }
        // ListNode* temp;
        // while(headA!=NULL){
        //     if(headA==headB){
        //         temp=headA;
        //         break;
        //     }
        //     headA=headA->next;
        //     headB=headB->next;
        // }
        // return temp;



        int count1=0;
        int count2=0;
        ListNode *currA=headA;
        ListNode *currB=headB;
        while(currA!=NULL){
            count1++;
            currA=currA->next;
        }
        while(currB!=NULL){
            count2++;
            currB=currB->next;
        }
        while(count1 > count2){
            count1--;
            headA=headA->next;
        }
        while(count1 < count2){
            count2--;
            headB=headB->next;
        }
        ListNode * temp;
        while(headA!=NULL){
            if(headA==headB){
                return headA;
            }
            headA=headA->next;
            headB=headB->next;
        }
        return nullptr;
    }
};