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
    ListNode* removeElements(ListNode* head, int val) {
        while(head && head->val == val)
            head = head->next;
        if(!head)   return NULL;
        ListNode* prev = head;
        ListNode* curr = head->next;
        while(curr) {
            if(curr->val == val) {
                prev->next = curr->next;
                curr->next = NULL;
                curr = prev;
            }
            prev = curr;
            curr = curr->next;
        }
        return head;
    }
};