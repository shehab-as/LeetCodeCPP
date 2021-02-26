/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool IsPart(ListNode* head, TreeNode* root) {
        if(!head)   return true;
        if(!root)   return false;
        if(head->val != root->val)  return false;
        return IsPart(head->next, root->left) || IsPart(head->next, root->right);
    }
    bool isSubPath(ListNode* head, TreeNode* root) {
        if(!root)   return false;
        return IsPart(head, root) || 
            isSubPath(head, root->left) ||
            isSubPath(head, root->right);
    }
};