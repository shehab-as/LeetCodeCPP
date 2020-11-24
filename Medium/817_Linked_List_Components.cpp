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
    int numComponents(ListNode* head, vector<int>& G) {
        unordered_set<int> existing(G.begin(), G.end());
        ListNode* curr = head;
        bool start_of_found = false;
        int no_of_components = 0;
        
        while(!existing.empty() && curr) {
            if(existing.find(curr->val) != existing.end()) {
                if(!start_of_found) 
                    no_of_components++;
                start_of_found = true;
                existing.erase(curr->val);
            }
            else 
                start_of_found = false;
            curr = curr->next;
        }
        return no_of_components;
    }
};