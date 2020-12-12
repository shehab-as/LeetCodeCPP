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
    pair<int, TreeNode*> DFS(TreeNode* root) {
        if(root == nullptr) return {0, root};

        auto l = DFS(root->left);
        auto r = DFS(root->right);
        
        if(l.first == r.first) return {1 + l.first, root};
        else if(l.first > r.first) return {1 + l.first, l.second};
        else return {1 + r.first, r.second};
    }

    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        return DFS(root).second;
    }
};