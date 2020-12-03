/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* increasingBST(TreeNode* root) {
        if(!root)   return nullptr;
        stack<TreeNode*> stk;
        TreeNode* dummy = new TreeNode(0);
        TreeNode* runner = dummy;
        TreeNode* curr = root;
        while(curr || !stk.empty()) {
            while(curr) {
                stk.push(curr);
                curr = curr->left;
            }
            curr = stk.top();
            stk.pop();
            runner->right = new TreeNode(curr->val);
            runner = runner->right;
            curr = curr->right;
        }
        return dummy->right;
    }
};