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
    vector<ListNode*> splitListToParts(ListNode* root, int k) {
        vector<ListNode*> Parts (k, NULL);
        int sz = 0;
        for(ListNode* runner = root; runner; runner=runner->next, sz++);
        int n = sz / k;     // part size.
        int extra = sz % k; // extra nodes.
        ListNode* runner = root;
        ListNode* prev = NULL;
        for(int i = 0; runner && i < k; i++, extra--) {
            Parts[i] = runner;
            for(int j = 0; j < n + (extra > 0); j++) {
                prev = runner;
                runner = runner->next;
            }
            prev->next = NULL;
        }
        return Parts;   
    }
};