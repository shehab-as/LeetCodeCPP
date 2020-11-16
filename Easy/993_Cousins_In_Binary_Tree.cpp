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
    bool isCousins(TreeNode* root, int x, int y) {
        int level_x, level_y;
        TreeNode* ParentOfX = nullptr;
        TreeNode* ParentOfY = nullptr;
        queue<TreeNode*> que;
        que.push(root);
        int level = 0;
        while(!que.empty()) {
            int N = que.size();
            for(int i = 0; i < N; i++) {
                TreeNode* front = que.front();
                que.pop();
                level_x = front->val == x ? level : level_x;
                level_y = front->val == y ? level : level_y;
                if(front->left) {
                    ParentOfX = front->left->val == x ? front : ParentOfX;
                    ParentOfY = front->left->val == y ? front : ParentOfY;
                    que.push(front->left);
                }
                if(front->right) {
                    ParentOfX = front->right->val == x ? front : ParentOfX;
                    ParentOfY = front->right->val == y ? front : ParentOfY;
                    que.push(front->right);
                }
            }
            level++;
        }
        return level_x == level_y && ParentOfX != ParentOfY;
    }
};