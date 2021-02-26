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
    int getDecimalValue(ListNode* head) {
        int N = 0;
        for(ListNode* runner = head; runner != NULL; runner = runner->next, N++);
        ListNode* runner = head;
        long decimal = 0;
        while(runner) {
            decimal += runner->val *pow(2, N-1);
            N--;
            runner = runner->next;
        }
        return decimal;
    }
};