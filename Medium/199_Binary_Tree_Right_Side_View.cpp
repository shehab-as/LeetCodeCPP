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
    vector<int> rightSideView(TreeNode* root) {
        if(!root)   return {};
        vector<int> result;
        queue<TreeNode*> node_queue;
        node_queue.push(root);
        while(!node_queue.empty()) {
            int n = node_queue.size();
            for(int i=0; i<n; i++) {
                TreeNode* temp = node_queue.front();
                node_queue.pop();
                if(temp->left)
                    node_queue.push(temp->left);
                if(temp->right)
                    node_queue.push(temp->right);
                if(i == (n-1))
                    result.push_back(temp->val);
            }
        }
        return result;
    }
};