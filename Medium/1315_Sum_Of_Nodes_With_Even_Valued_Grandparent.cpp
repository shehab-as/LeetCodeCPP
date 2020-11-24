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
    void SumEvenGrandPa(TreeNode* N, TreeNode* P, TreeNode* G, int& sum) {
        if(!N)    
            return;
        if(G && G->val % 2 == 0) {
            sum += N->val;
        }
        SumEvenGrandPa(N->left, N, P, sum);
        SumEvenGrandPa(N->right, N, P, sum);
        return;
    }
    int sumEvenGrandparent(TreeNode* root) {
        int sum = 0;
        SumEvenGrandPa(root, nullptr, nullptr, sum);
        return sum;
    }
};