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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root)   return {};
        queue<TreeNode*> q;
        q.push(root);
        vector<vector<int>> result;
        int depth = 1;
        while(!q.empty()) {
            int sz = q.size();
            vector<int> level;
            for(int i = 0; i < sz; i++) {
                auto temp = q.front();  q.pop();
                level.push_back(temp->val);
                if(temp->left)  q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }
            if(depth % 2 == 0)  
                reverse(level.begin(), level.end());
            result.push_back(level);
            depth++;
        }
        return result;
    }
};