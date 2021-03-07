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
    void DFS(TreeNode* root, int minval, int maxval, int &res) {
        if(!root)
            return;
        if(minval != INT_MIN)
            res = min(res, root->val - minval);
        if(maxval != INT_MAX)
            res = min(res, maxval - root->val);
        DFS(root->left, minval, root->val, res);
        DFS(root->right, root->val, maxval, res);
        
    }
    int getMinimumDifference(TreeNode* root) {
        int res = INT_MAX;
        DFS(root, INT_MIN, INT_MAX, res);
        return res;
    }
};
