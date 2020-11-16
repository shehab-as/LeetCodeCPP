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
    void DFS(TreeNode* child, TreeNode* parent, int& sum) {
        if(!child)  return;
        DFS(child->left, child, sum);
        if(!child->left && !child->right) {
            if(parent->left == child)
                sum += child->val;
            return;
        }
        DFS(child->right, child, sum);
    }
    int sumOfLeftLeaves(TreeNode* root) {
        if(!root)   return 0;
        if(!root->left && !root->right) return 0;
        int sum = 0;
        DFS(root, NULL, sum);
        return sum;
    }
};