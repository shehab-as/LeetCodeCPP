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
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        if(!original)   return NULL;
        if(target == original)  return cloned;

        queue<TreeNode*> q1;
        queue<TreeNode*> q2;
        q1.push(original);
        q2.push(cloned);
        while(!q1.empty()) {
            TreeNode* temp1 = q1.front(); q1.pop();
            TreeNode* temp2 = q2.front(); q2.pop();
            if(temp1 == target) return temp2;
            if(temp1->left) { 
                q1.push(temp1->left);
                q2.push(temp2->left);
            }
            if(temp1->right) {
                q1.push(temp1->right);
                q2.push(temp2->right);
            }
        }
        return NULL;
    }
};