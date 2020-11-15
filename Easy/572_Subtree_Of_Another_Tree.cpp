/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
bool Identical(TreeNode* t1, TreeNode* t2) {
    if(!t1 && !t2)  return true;
    if(!t1 || !t2)  return false;
    if(t1->val != t2->val)  return false;
    return Identical(t1->left, t2->left) && Identical(t1->right, t2->right);
}

class Solution {
public:
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if(!s)  return false;
        if(!t)  return true;
        if(Identical(s,t))  return true;
        return isSubtree(s->left, t) || isSubtree(s->right, t);
    }
};