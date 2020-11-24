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
    // Recursive
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(!root)   return new TreeNode(val);
        if(val > root->val)
            root->right = insertIntoBST(root->right, val);
        else 
            root->left = insertIntoBST(root->left, val);
        return root;
    }
};

    // Iterative 
    // TreeNode* insertIntoBST(TreeNode* root, int val) {
    //     if(!root)   return new TreeNode(val);
    //     TreeNode* prev = NULL;
    //     TreeNode* curr = root;
    //     while(curr) {
    //         prev = curr;
    //         curr = (val > curr->val) ? curr->right : curr->left;
    //     }
    //     if(val > prev->val)
    //         prev->right = new TreeNode(val);
    //     else
    //         prev->left = new TreeNode(val);
    //     return root;
    // }