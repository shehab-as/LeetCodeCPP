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
    void InOrder(TreeNode* t, vector<int>& v) {
        if(t->left)   InOrder(t->left, v);
        v.push_back(t->val);
        if(t->right)    InOrder(t->right, v);
    }
    bool isValidBST(TreeNode* root) {
        if(!root)   return true;
        vector<int> v;
        InOrder(root, v);
        for(int i = 0; i < v.size() - 1; i++) {
            if(v[i] >= v[i+1])
                return false;
        }
        return true;
    }
};
