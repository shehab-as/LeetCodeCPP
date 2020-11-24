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
    void InOrder(TreeNode* t, int& k, int& ans) {
        if(!t)  return;
        InOrder(t->left, k, ans);
        if(--k == 0)    ans = t->val;
        InOrder(t->right, k, ans);
    }
    int kthSmallest(TreeNode* root, int k) {
        int ans = -1;
        InOrder(root, k, ans);
        return ans;
    }
};