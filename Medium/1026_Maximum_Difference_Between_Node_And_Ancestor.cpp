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
    void FindMaxDiff(TreeNode* ancestor, TreeNode* child, int& global_max_diff) {
        if(!ancestor || !child) {
            return;
        }
        int curr_diff = abs(ancestor->val - child->val);
        // cout<<"Diff between Anc: "<<ancestor->val<<" | Child: "<<child->val<<" -> "<<curr_diff<<endl;
        global_max_diff = max(global_max_diff, curr_diff);
        FindMaxDiff(ancestor, child->left, global_max_diff);
        FindMaxDiff(ancestor, child->right, global_max_diff);
    }
    
    int maxAncestorDiff(TreeNode* root) {
        if(!root) {
            return 0;
        }
        int global_max_diff = 0;
        queue<TreeNode*> Que;
        Que.push(root);
        while(!Que.empty()) {
            auto ancestor = Que.front();    
            Que.pop();
            // cout<<"DFS FOR ANCESTOR: "<<ancestor->val<<endl;
            FindMaxDiff(ancestor, ancestor, global_max_diff);
            if(ancestor->left)  {
                Que.push(ancestor->left);
            }
            if(ancestor->right) {
                Que.push(ancestor->right);
            }
        }
        return global_max_diff;
    }
};