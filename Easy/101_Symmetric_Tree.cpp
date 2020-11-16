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
    bool isSymmetric(TreeNode* root) {
        if(!root)   return true;
        queue<TreeNode*> q;
        q.push(root->left);
        q.push(root->right);
        while(!q.empty()) {
            TreeNode* leftNode = q.front();
            q.pop();
            TreeNode* rightNode = q.front();
            q.pop();
            if(leftNode && rightNode) {
                if(leftNode->val != rightNode->val) return false;
                q.push(leftNode->left);
                q.push(rightNode->right);
                q.push(leftNode->right);
                q.push(rightNode->left);
            }
            if((!leftNode && rightNode) || (!rightNode && leftNode)) return false;
        }
        return true;
    }
};