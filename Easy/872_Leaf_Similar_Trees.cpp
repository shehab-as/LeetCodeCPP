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
    void DFS(TreeNode* root, vector<int>& v) {
        if(root->left)
            DFS(root->left, v);
        if(root->right)
            DFS(root->right, v);
        if(!root->left && !root->right)
            v.push_back(root->val);
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> v1;
        vector<int> v2;
        DFS(root1, v1);
        DFS(root2, v2);
        return (v1 == v2);
    }
};