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
    int minDepth(TreeNode* root) {
        if(!root)   return 0;
        int d = 0;
        queue<TreeNode*> Q;
        Q.push(root);
        while(!Q.empty()) {
            d++;
            int Count = Q.size();
            for(int i=0; i<Count; i++) {
                TreeNode* tmp = Q.front();
                Q.pop();
                if(!tmp->left && !tmp->right)
                    return d;
                if(tmp->left)   Q.push(tmp->left);
                if(tmp->right)  Q.push(tmp->right);
            }
        }
        return d;
    }
};