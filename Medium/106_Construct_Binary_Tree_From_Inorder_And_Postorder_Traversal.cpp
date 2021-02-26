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
    TreeNode* buildRecTree(int L, int R, int p_indx, const vector<int>&in, const vector<int>&post) {
        if(L > R)
            return nullptr;
        TreeNode* t = new TreeNode(post[p_indx]);
        if(L == R)  return t;
        int Index;
        for(Index = L; Index <= R; Index++) {
            if(in[Index] == t->val)   
                break;
        }
        // cout<<"("<<L<<" - "<<Index-1<<") <- ["<<t->val<<"] -> ("<<Index+1<<", "<<R<<") "<<endl;
        t->right = buildRecTree(Index+1, R, p_indx-1, in, post);
        t->left = buildRecTree(L, Index-1, p_indx-1-(R-Index), in, post);
        return t;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(postorder.empty() || inorder.empty())    return nullptr;
        int len = postorder.size() - 1;
        return buildRecTree(0, len, len, inorder, postorder);
    }
};