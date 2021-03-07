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
    vector<double> averageOfLevels(TreeNode* root) {
        if(!root) {
            return {};
        }
        vector<double> result;
        queue<TreeNode*> Q;
        Q.push(root);
        while(!Q.empty()) {
            double sz = Q.size();
            double sum = 0.0;
            for(int i = 0; i < sz; i++) {
                auto temp = Q.front();
                Q.pop();
                sum += temp->val;
                if(temp->left)  {
                    Q.push(temp->left);
                }
                if(temp->right) {
                    Q.push(temp->right);
                }
            }
            double avg = sum / sz;
            result.push_back(avg);
        }
        return result;
    }
};