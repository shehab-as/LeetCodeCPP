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
        if(t->left)     InOrder(t->left, v);
        v.push_back(t->val);
        if(t->right)    InOrder(t->right, v);
    }
    int minDiffInBST(TreeNode* root) {
        if(!root)   return 0;
        vector<int> v;
        InOrder(root, v);
        int min_d = INT_MAX;
        for(int i = 0; i < v.size() - 1; i++) 
            min_d = min(min_d, v[i+1]-v[i]);
        return min_d;
    }
};