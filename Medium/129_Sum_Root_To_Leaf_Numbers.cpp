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
private: 
    int total_sum = 0;
public:
    void DFS(TreeNode* root, int curr_sum) {
        if(!root)   return;
        curr_sum = (curr_sum * 10) + root->val;
        if(root->left == root->right) {
            total_sum += curr_sum;
            return;
        }
        DFS(root->left, curr_sum);
        DFS(root->right, curr_sum);
        curr_sum = (curr_sum / 10);
    }
    int sumNumbers(TreeNode* root) {
        if(!root)   return 0;
        DFS(root, 0);
        return total_sum;
    }
};