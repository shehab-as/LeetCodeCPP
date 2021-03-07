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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        if(!root)   return result;
        stack<TreeNode*> node_stack;
        node_stack.push(root);
        while(!node_stack.empty()) {
            TreeNode *temp = node_stack.top();
            node_stack.pop();
            result.push_back(temp->val);
            if(temp->right)
                node_stack.push(temp->right);
            if(temp->left)
                node_stack.push(temp->left);
        }
        return result;
    }
};