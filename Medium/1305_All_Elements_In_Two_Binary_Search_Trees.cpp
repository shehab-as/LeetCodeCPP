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
    void DFS(TreeNode* t, vector<int>& v) {
        if(!t)  return;
        DFS(t->left, v);
        v.push_back(t->val);
        DFS(t->right, v);
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> v1, v2;
        DFS(root1, v1);
        DFS(root2, v2);
        vector<int> result;
        int i1 = 0, i2 = 0;
        while( i1 < v1.size() && i2 < v2.size() ) {
            if(v1[i1] <= v2[i2]) {
                result.push_back(v1[i1++]);
            }
            else {
                result.push_back(v2[i2++]);
            }
        }
        while(i1 < v1.size())   result.push_back(v1[i1++]);
        while(i2 < v2.size())   result.push_back(v2[i2++]);
        
        return result;
    }
};