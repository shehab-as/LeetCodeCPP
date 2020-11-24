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
    void PostOrder(TreeNode* root, vector<int>& v) {
        if(!root)   return;
        PostOrder(root->left, v);
        PostOrder(root->right, v);
        v.push_back(root->val);
    }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> v;
        PostOrder(root, v);
        return v;
    }
};