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
    int diameter = 0;
    int getHeight(TreeNode* t) {
        if(!t)  return 0;
        int leftHeight = getHeight(t->left);
        int rightHeight = getHeight(t->right);
        diameter = max(diameter, leftHeight + rightHeight);
        return max(leftHeight, rightHeight) + 1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        getHeight(root);
        return diameter;
    }
};