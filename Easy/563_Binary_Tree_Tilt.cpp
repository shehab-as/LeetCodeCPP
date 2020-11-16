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
    int DFS(TreeNode* root, int& tilt_total) {
        if(!root)   return 0;
        int left_sum = DFS(root->left, tilt_total);
        int right_sum = DFS(root->right, tilt_total);
        tilt_total += abs(left_sum - right_sum);
        return left_sum + root->val + right_sum;
    }
    int findTilt(TreeNode* root) {
        if(!root) {
            return 0;
        }
        int result = 0;
        DFS(root, result);
        return result;
    }
};