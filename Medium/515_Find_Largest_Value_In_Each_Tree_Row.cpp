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
    void DFS(TreeNode* root, int index, vector<int>& maxes) {
        if(index >= maxes.size()) 
            maxes.push_back(root->val);
        else if(root->val > maxes[index])
            maxes[index] = root->val;
        if(root->left)
            DFS(root->left, index+1, maxes);
        if(root->right)
            DFS(root->right, index+1, maxes);
    }
    vector<int> largestValues(TreeNode* root) {
        if(!root)
            return {};
        vector<int> maxes;
        DFS(root, 0, maxes);
        return maxes;
    }
};