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
    void DFS(TreeNode* root, const int& sum, int curr_sum, int& ways) {
        if(!root) return;
        if(curr_sum + root->val == sum) {
            ways++;
        }
        DFS(root->left, sum, curr_sum+root->val, ways);
        DFS(root->right, sum, curr_sum+root->val, ways);
    }
    int pathSum(TreeNode* root, int sum) {
        if(!root)   return 0;
        int ways = 0;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            auto temp = q.front();  q.pop();
            if(temp->left)  q.push(temp->left);
            if(temp->right) q.push(temp->right);
            DFS(temp, sum, 0, ways);
        }
        return ways;
    }
};