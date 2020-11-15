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
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* fwd = NULL;
        while(head) {
            fwd = head->next;
            head->next = prev;
            prev = head;
            head = fwd;
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {
        if(!head)   return true;
        ListNode* fast = head;
        ListNode* slow = head;
        while(fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        slow->next = reverseList(slow->next);
        slow = slow->next;
        while(slow) {
            if(head->val != slow->val)  return false;
            head = head->next;
            slow = slow->next;
        }
        return true;
    }
};