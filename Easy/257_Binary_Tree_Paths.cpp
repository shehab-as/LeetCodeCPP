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
    void PreOrder(TreeNode* root, vector<string>& all_paths, string path) {
        path += to_string(root->val);
        if(!root->left && !root->right)
            all_paths.push_back(path);
        if(root->left)
            PreOrder(root->left, all_paths, path + "->");
        if(root->right)
            PreOrder(root->right, all_paths, path + "->");
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        if(!root)   return {};
        vector<string> all_paths;
        PreOrder(root, all_paths, "");
        return all_paths;
    }
};