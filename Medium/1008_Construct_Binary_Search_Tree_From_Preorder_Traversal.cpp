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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        TreeNode dummy(INT_MAX);
        stack<TreeNode*> Stk ({&dummy});
        
        for(int key : preorder) {
            TreeNode* node = new TreeNode(key);
            TreeNode* parent = nullptr;
            while(Stk.top()->val < key) {
                parent = Stk.top();
                Stk.pop();
            }
            if(parent)
                parent->right = node;
            else
                Stk.top()->left = node;
            Stk.push(node);
        }
        return dummy.left;
    }
};

    // TreeNode* AddNode(TreeNode* root, int key) {
    //     if(!root)   return new TreeNode(key);
    //     if(key > root->val) 
    //         root->right = AddNode(root->right, key);
    //     else if(key < root->val)
    //         root->left = AddNode(root->left, key);
    //     return root;
    // }
    // TreeNode* bstFromPreorder(vector<int>& preorder) {
    //     TreeNode* root = nullptr;
    //     for(int key : preorder)
    //         root = AddNode(root, key);
    //     return root;
    // }