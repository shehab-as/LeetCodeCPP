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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty())   return NULL;
        ListNode* dummy = new ListNode(0);
        ListNode* curr = dummy;
        while(true) {
            int min_val = INT_MAX;
            bool all_visited = true;
            for(int j = 0; j < lists.size(); j++) {
                if(lists[j] != NULL) {
                    min_val = min(lists[j]->val, min_val);
                    all_visited = false;
                }
            }
            if(all_visited) break;
            for(int j = 0; j < lists.size(); j++) {
                if(lists[j] != NULL && min_val == lists[j]->val) {
                    curr->next = new ListNode(min_val);
                    curr = curr->next;
                    lists[j] = lists[j]->next;
                }
            }
        }
        return dummy->next;
    }
};