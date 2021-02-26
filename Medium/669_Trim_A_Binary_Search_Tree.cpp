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
    TreeNode* Trim(TreeNode* node, int L, int R) {
        if(!node)   return nullptr;
        if(node->val < L)   
            return Trim(node->right, L, R);
        if(node->val > R) 
            return Trim(node->left, L, R);
            
        node->left = Trim(node->left, L, R);
        node->right = Trim(node->right, L, R);
        // node->val -> [L, R]
        return node;
    }
    TreeNode* trimBST(TreeNode* root, int L, int R) {
        if(!root)   return nullptr;
        return Trim(root, L, R);
    }
};