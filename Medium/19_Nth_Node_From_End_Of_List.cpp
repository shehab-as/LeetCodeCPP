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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head) 
            return NULL;
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *slow = head, *fast = head, *prev = dummy;
        while(n) {
            fast = fast->next;
            n--;
        }
        while(fast) {
            fast = fast->next;
            prev = slow;
            slow = slow->next;
        }
        prev->next = slow->next;
        slow->next = NULL;
        delete slow;
        return dummy->next;
    }
};