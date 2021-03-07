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
    void build_string(TreeNode* t, string& s)
    {
        if(!t) {
            s += "()";
            return;
        }
        if(t)
            s += to_string(t->val);

        if(t->left) {
            s += "(";
            build_string(t->left, s);
            s += ")";
        }
        else if(t->right)
            s += "()";
        
        if(t->right) {
            s += "(";
            build_string(t->right, s);
            s += ")";
        }
    }
    
    string tree2str(TreeNode* t) {
        string s = "";
        if(!t)
            return s;
        build_string(t, s);
        return s;
    }
};