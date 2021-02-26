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
        ListNode* runner = head;
        ListNode* prev = NULL;
        unordered_set<int> dups;
        while(runner) {
            prev = runner;
            runner = runner->next;
            if(runner && prev->val == runner->val)
                dups.insert(runner->val);
        }
        while(head && dups.find(head->val) != dups.end())
            head = head->next;
        runner = head;
        prev = NULL;
        while(runner) {
            prev = runner;
            runner = runner->next;
            while(runner && dups.find(runner->val) != dups.end()) {
                ListNode *temp = runner;
                prev->next = temp->next;
                temp->next = NULL;
                delete temp;
                runner = prev->next;
            }
        }
        return head;
    }
};