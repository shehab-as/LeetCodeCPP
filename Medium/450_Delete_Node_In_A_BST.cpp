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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root)   return root;
        if(key > root->val)         root->right = deleteNode(root->right, key);
        else if(key < root->val)    root->left = deleteNode(root->left, key);
        else //if(key == root->val) 
        {
            if(!root->left) {
                TreeNode* RightChild = root->right;
                delete root;
                return RightChild;
            }
            if(!root->right) {
                TreeNode* LeftChild = root->left;
                delete root;
                return LeftChild;
            }
            TreeNode* Successor = root->right;
            while(Successor->left)  Successor = Successor->left;
            swap(root->val,Successor->val);
            root->right = deleteNode(root->right, key);
        }
        return root;
    }
};