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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head)   return NULL;
        ListNode* prev = head;
        ListNode* curr = head->next;
        while(prev && curr) {
            if(prev->val == curr->val) {
                ListNode* temp = curr;
                prev->next = temp->next;
                temp->next = NULL;
                delete temp;
                curr = prev;
            }
            prev = curr;
            curr = curr->next;
        }
        return head;
    }
};