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
    // Swap between Node A and Node B.
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* curr = head;
        int pos = 1;
        // Get Node A.
        while(curr && pos < k) {
            curr = curr->next;
            pos++;
        }
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast && k > 1) {
            fast = fast->next;
            k--;
        }
        // Get Node B.
        while(slow && fast && fast->next) {
            slow = slow->next;
            fast = fast->next;
        }
        swap(slow->val, curr->val);
        return head;
    }
};