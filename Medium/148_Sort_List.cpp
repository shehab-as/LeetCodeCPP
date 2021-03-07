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
    ListNode* sortList(ListNode* head) {
        if(!head || !head->next)
            return head;
        vector<int> V;
        ListNode* runner = head;
        while(runner)
        {
            V.push_back(runner->val);
            runner = runner->next;
        }
        sort(V.begin(), V.end());
        runner = head;
        for(int i=0; i<V.size(); i++)
        {
            runner->val = V[i];
            runner = runner->next;
        }
        return head;
    }
};