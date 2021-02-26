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
    int SumRec(TreeNode* root, int val) {
        if(!root)   return 0;
        val = 2 * val + root->val;
        return root->left == root->right ? val : SumRec(root->left, val) + SumRec(root->right, val);
        
    }
    int sumRootToLeaf(TreeNode* root) {
        if(!root)   return 0;
        return SumRec(root, 0);
    }
};