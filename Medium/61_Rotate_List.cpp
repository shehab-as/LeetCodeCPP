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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !k)
            return head;
        deque<int> dq;
        ListNode *runner = head;
        int size = 0;
        while(runner) {
            size++;
            dq.push_back(runner->val);
            runner = runner->next;
        }
        delete runner, head;
        k %= size;
        while(k) {
            dq.push_front(dq.back());
            dq.pop_back();
            k--;
        }
        ListNode *result = new ListNode(dq.front());
        head = result;
        dq.pop_front();
        while(!dq.empty()) {
            result->next = new ListNode(dq.front());
            result = result->next;
            dq.pop_front();
        }
        return head;
    }
};