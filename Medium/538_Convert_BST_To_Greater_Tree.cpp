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
    void DFS(TreeNode* root, int& curr_sum) {
        if(!root)   return;
        DFS(root->right, curr_sum);
        root->val += curr_sum;
        curr_sum = root->val;
        DFS(root->left, curr_sum);
    }
    TreeNode* convertBST(TreeNode* root) {
        int sum = 0;
        DFS(root, sum);
        return root;
        
    }
};