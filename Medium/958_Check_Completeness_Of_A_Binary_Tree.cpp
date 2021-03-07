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
    bool isCompleteTree(TreeNode* root) {
        vector<TreeNode*> BFS;
        int i = 0;
        BFS.push_back(root);
        while(i < BFS.size() && BFS[i]) {
            BFS.push_back(BFS[i]->left);
            BFS.push_back(BFS[i]->right);
            i++;
        }
        while(i < BFS.size() && !BFS[i])
            i++;
        
        return i == BFS.size();
        
    }
};