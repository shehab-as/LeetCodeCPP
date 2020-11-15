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
    int DFS(TreeNode* root) {
        if(!root)   return 0;
        int left_h = DFS(root->left);
        if(left_h == -1)    return -1;
        int right_h = DFS(root->right);
        if(right_h == -1)   return -1;
        
        if(abs(left_h - right_h) > 1)   return -1;
        return max(left_h, right_h) + 1;
        
    }
    bool isBalanced(TreeNode* root) {
        return DFS(root) != -1;
    }
};