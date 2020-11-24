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
    int maxLevelSum(TreeNode* root) {
        int global_max = INT_MIN;
        int global_level = 1;
        int curr_level = 1;
        
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()) {
            int sz = q.size();
            int curr_max = 0;
            for(int i = 0; i < sz; i++) {
                TreeNode* temp = q.front();
                q.pop();
                curr_max += temp->val;
                if(temp->left)  q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }
            
            if(curr_max > global_max) {
                global_level = curr_level;
                global_max = curr_max;
            }
            
            curr_level++;
        }
        return global_level;
    }
};