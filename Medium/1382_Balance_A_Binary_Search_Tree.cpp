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
    TreeNode* buildBST(const vector<int>& values, int left, int right) {
        if(left >= right)   return NULL;
        int mid = (left + right) / 2;
        TreeNode* t= new TreeNode(values[mid]);
        t->left = buildBST(values, left, mid);
        t->right = buildBST(values, mid + 1, right);
        return t;
    }
    TreeNode* balanceBST(TreeNode* root) {
        if(!root)   return NULL;
        vector<int> values;
        function<void(TreeNode*)> InOrder = [&](TreeNode* t) {
            if(!t)  return;
            InOrder(t->left);
            values.push_back(t->val);
            InOrder(t->right);
        };
        InOrder(root);
        return buildBST(values, 0, values.size());
        
    }
};
