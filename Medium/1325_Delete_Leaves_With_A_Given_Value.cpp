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
    void RemoveLeaves(TreeNode* root, int target) {
        if(!root)   return;
        RemoveLeaves(root->left, target);
        RemoveLeaves(root->right, target);
        if(root->left) {
            if(!root->left->left && !root->left->right && root->left->val == target) {
                delete root->left;
                root->left = NULL;
            }
        }
        if(root->right) {
            if(!root->right->left && !root->right->right && root->right->val == target) {
                delete root->right;
                root->right = NULL;
            }
        }
    }
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        RemoveLeaves(root, target);
        if(root->val == target && !root->left && !root->right)
            return NULL;
        return root;
    }
};