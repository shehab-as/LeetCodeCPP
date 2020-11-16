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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(!l1 && !l2)  return NULL;
        if(!l1) return l2;
        if(!l2) return l1;
        ListNode *head = new ListNode(0);
        ListNode *result = head;
        while(l1 && l2) {
            if(l1->val <= l2->val) {
                result->next = l1;
                l1 = l1->next;
            }
            else {
                result->next = l2;
                l2 = l2->next;
            }
            result = result->next;
        }
        if(l1)  result->next = l1;
        if(l2)  result->next = l2;
        
        return head->next;
        
    }
};