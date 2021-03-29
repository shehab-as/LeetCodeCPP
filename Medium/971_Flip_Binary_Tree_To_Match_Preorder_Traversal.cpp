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
private:
    vector<int> flipped;
    int i = 0;
public:    
    vector<int> flipMatchVoyage(TreeNode* root, vector<int>& v) {
        return dfs(root, v) ? flipped : vector<int>{-1};
    }

    bool dfs(TreeNode* node, vector<int>& v) {
        if (!node) 
            return true;
        if (node->val != v[i++]) 
            return false;
        if (node->left && node->left->val != v[i]) {
            flipped.push_back(node->val);
            swap(node->left, node->right);
        }
        return dfs(node->left, v) && dfs(node->right, v);
    }
};