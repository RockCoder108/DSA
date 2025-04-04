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
    ListNode* deleteMiddle(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return nullptr;
        }
        ListNode* slow=head;
        ListNode* fast=head;
        ListNode* onePrev=nullptr;
        while(fast!=nullptr && fast->next!=nullptr){
            fast=fast->next->next;
            onePrev = slow;
            slow = slow->next;
        }
        onePrev->next = slow->next;
        return head;
    }
};