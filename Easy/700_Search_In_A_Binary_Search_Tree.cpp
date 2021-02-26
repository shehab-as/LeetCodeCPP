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
    TreeNode* searchBST(TreeNode* root, int val) {
        if(!root)   return nullptr;
        TreeNode* curr = root;
        while(curr) {
            if(curr->val == val)    break;
            curr = (curr->val > val) ? curr->left : curr->right;
        }
        return curr;
    }
};