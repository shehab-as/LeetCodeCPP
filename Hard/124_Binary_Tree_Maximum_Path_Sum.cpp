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
    int DFS(TreeNode* root, int& res) {
        if(!root)   return 0;
        int L = DFS(root->left, res);
        int R = DFS(root->right, res);
        
        int curr_sum = max(max(L, R) + root->val, root->val);
        int max_top = max(curr_sum, L + root->val + R);
        res = max(res, max_top);
        
        return curr_sum;
    }
    
    int maxPathSum(TreeNode* root) {
        if(!root)   return 0;
        int res = INT_MIN;
        DFS(root, res);
        return res;
    }
};