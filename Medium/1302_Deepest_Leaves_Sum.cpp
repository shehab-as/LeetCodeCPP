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
private:
    int deepest = 0;
public:
    void DFS(TreeNode* t, int depth, int& sum) {
        if(!t)  return;
        DFS(t->left, depth+1, sum);
        if(depth == deepest) {
            sum += t->val;
        }
        else if(depth > deepest) {
            deepest = depth;
            sum = t->val;
        }
        DFS(t->right, depth+1, sum);
        
    }
    int deepestLeavesSum(TreeNode* root) {
        if(!root)   return 0;
        int sum = 0;
        DFS(root, 0, sum);
        return sum;
    }
};