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
    vector<int> inorderTraversal(TreeNode* root) {
        if(!root)   return {};
        vector<int> v;
        stack<TreeNode*> node_stack;
        while(root || !node_stack.empty()) {
            while(root) {
                node_stack.push(root);
                root = root->left;
            }
            root = node_stack.top();
            node_stack.pop();
            v.push_back(root->val);
            root = root->right;
        }
        return v;
    }
};


// class Solution {
// public:
//     vector<int> inorderTraversal(TreeNode* root) {
//         vector<int> nodes;
//         stack<TreeNode*> todo;
//         while (root || !todo.empty()) {
//             while (root) {
//                 todo.push(root);
//                 root = root -> left;
//             }
//             root = todo.top();
//             todo.pop();
//             nodes.push_back(root -> val);
//             root = root -> right;
//         }
//         return nodes;
//     }
// };



// class Solution {
// public:
//     vector<int> inorderTraversal(TreeNode* root) {
//         vector<int> nodes;
//         std::stack<TreeNode*> toVisit;
//         while(1) {
//             while(root) { toVisit.push(root); root=root->left; }
//             if(toVisit.empty()) break;
//             root=toVisit.top(); toVisit.pop();
//             nodes.push_back(root->val);
//             root=root->right;
//         }
//         return nodes;
//     }
// };