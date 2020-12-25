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
    ListNode* swapPairs(ListNode* head) {
        if(!head || !head->next)    return head;
        ListNode* dummy = new ListNode(0);
        ListNode* prev = dummy;
        
        prev->next = head;
        ListNode* curr = head;
        ListNode* fwd = head->next;

        while(curr && fwd) {
            prev->next = fwd;
            curr->next = fwd->next;
            fwd->next = curr;
            
            prev = curr;
            curr = curr->next;
            fwd = curr ? curr->next : curr;
        }
        
        return dummy->next;
    }
};
