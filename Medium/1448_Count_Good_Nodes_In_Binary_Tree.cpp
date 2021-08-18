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
private:
    int searchGoodNodes(TreeNode* root, int curr_max) {
        if(!root) {
            return 0;
        }
        int currGoodNode = root->val >= curr_max ? 1 : 0;
        int updated_max = max(root->val, curr_max);
        int leftGoodNodes = searchGoodNodes(root->left, updated_max);
        int rightGoodNodes = searchGoodNodes(root->right, updated_max);

        return leftGoodNodes + rightGoodNodes + currGoodNode;
    }
public:
    int goodNodes(TreeNode* root) {
        return searchGoodNodes(root, INT_MIN);
    }
};