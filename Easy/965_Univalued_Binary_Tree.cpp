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
    bool DFS(TreeNode *t, const int val) {
        if(!t)  return true;
        return t->val == val && DFS(t->left, val) && DFS(t->right, val);
    }
    bool isUnivalTree(TreeNode* root) {
        if(!root)   return true;
        return DFS(root, root->val);
    }
};