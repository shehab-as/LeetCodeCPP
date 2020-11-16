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
    TreeNode* prev = new TreeNode(INT_MIN);
    TreeNode* first = nullptr;
    TreeNode* second = nullptr;
public:
    void DFS(TreeNode* root) {
        if(!root)   
            return;
        DFS(root->left);
        if(!first && prev->val > root->val)
            first = prev;
        if(first && prev->val > root->val)
            second = root;
        prev = root;
        DFS(root->right);
        return;
    }
    void recoverTree(TreeNode* root) {
        if(!root)
            return;
        DFS(root);
        swap(first->val, second->val);
        return;
    }
};