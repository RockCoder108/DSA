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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        set<int> number;

        for(auto i : nums){
            number.insert(i);
        }

        ListNode* prev =NULL;
        ListNode* curr = head;
        while(curr!=NULL){
            if(number.contains(curr->val)){
                if(prev ==NULL){
                    head = head->next;
                }else{
                    prev->next = curr->next;
                }
            }else{
                prev = curr;
            }
            curr = curr->next;
        }
        return head;
    }
};