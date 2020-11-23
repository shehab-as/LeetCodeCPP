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
    int DFS(TreeNode* root, int& left, int& right) {
        if(!root)   return 0;
        int left_left = 0, left_right = 0;
        int right_left = 0, right_right = 0;
        left = DFS(root->left, left_left, left_right);
        right = DFS(root->right, right_left, right_right);
        
        int sum_grand_children = left_left + left_right + right_left + right_right;
        int sum_children = left + right;
        return max(root->val + sum_grand_children, sum_children);
    }
    int rob(TreeNode* root) {
        if(!root)   return 0;
        int left = 0, right = 0;
        return DFS(root, left, right);
    }
};