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
    int findSecondMinimumValue(TreeNode* root) {
        if(!root)   return -1;
        int left = -1, right = -1;
        if(root->left) {
            left = root->val == root->left->val ? findSecondMinimumValue(root->left) : root->left->val;
        }
        if(root->right) {
            right = root->val == root->right->val ? findSecondMinimumValue(root->right) : root->right->val;
        }
        if(left != -1 && right != -1)
            return min(left, right);
        return left == -1 ? right : left;
    }
};