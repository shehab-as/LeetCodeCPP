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
    TreeNode* addOneRow(TreeNode* root, int v, int d) {
        if( d == 1 ) {
            TreeNode* newRoot = new TreeNode(v);
            newRoot->left = root;
            return newRoot;
        }
        queue<TreeNode*> Q;
        Q.push(root);
        while(!Q.empty()) {
            int sz = Q.size();
            for(int i = 0; i < sz; i++) {
                TreeNode* curr = Q.front();
                Q.pop();
                TreeNode* temp;
                if(d-1 == 1) {
                    TreeNode* LNode = new TreeNode(v);
                    temp = curr->left;
                    curr->left = LNode;
                    LNode->left = temp;

                    TreeNode* RNode = new TreeNode(v);
                    temp = curr->right;
                    curr->right = RNode;
                    RNode->right = temp;
                }
                else {
                    if(curr->left)  Q.push(curr->left);
                    if(curr->right) Q.push(curr->right);
                }
            }
            d--;
        }
        return root;
    }
};