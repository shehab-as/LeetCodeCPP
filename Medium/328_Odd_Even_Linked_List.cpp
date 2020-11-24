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
    ListNode* oddEvenList(ListNode* head) {
        if(!head)   return NULL;
        ListNode* even_odd_head = new ListNode(0);
        ListNode* odd_runner = head;
        ListNode* runner = even_odd_head;
        while(odd_runner) {
            runner->next = new ListNode(odd_runner->val);
            runner = runner->next;
            odd_runner = (odd_runner->next) ? odd_runner->next->next : NULL;
        }
        delete odd_runner;
        ListNode* even_runner = head->next;
        while(even_runner) {
            runner->next = new ListNode(even_runner->val);
            runner = runner->next;
            even_runner = (even_runner->next) ? even_runner->next->next : NULL;
        }
        return even_odd_head->next;
    }
};