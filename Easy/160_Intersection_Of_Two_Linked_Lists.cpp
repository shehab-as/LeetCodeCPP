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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(!headA || !headB)    return NULL;
        ListNode* runnerA = headA;
        ListNode* runnerB = headB;
        int size_A = 0, size_B = 0;
        for(; runnerA; size_A++, runnerA=runnerA->next);
        for(; runnerB; size_B++, runnerB=runnerB->next);
        int diff = abs(size_A - size_B);
        ListNode* result = (size_A > size_B) ? headA : headB;
        ListNode* shortest = (size_A > size_B) ? headB : headA;
        while(diff) {
            result = result->next;
            diff--;
        }
        while(result) {
            if(result == shortest)  return result;
            result = result->next;
            shortest = shortest->next;
        }
        return NULL;
    }
};