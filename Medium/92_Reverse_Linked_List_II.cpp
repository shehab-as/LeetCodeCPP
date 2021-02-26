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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode* dummy = new ListNode(0);
        ListNode* prev = dummy;
        dummy->next = head;
        for(int i = 0; i < m - 1; i++, prev = prev->next);
        ListNode* curr = prev->next;
        for(int i = 0; i < n - m; i++) {
            ListNode* temp = prev->next;
            prev->next = curr->next;
            curr->next = curr->next->next;
            prev->next->next = temp;
        }
        return dummy->next;
    }
};