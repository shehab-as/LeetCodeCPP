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
private:
    ListNode* _head;
    int _len = 0;
public:
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    Solution(ListNode* head) : _head(head) {
        ListNode* curr = _head;
        while(curr) {
            _len++;
            curr = curr->next;
        }
    }
    
    /** Returns a random node's value. */
    int getRandom() {
        int index = rand() % _len;
        ListNode* runner = _head;
        while(index-- && runner) {
            runner = runner->next;
        }
        return runner->val;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */