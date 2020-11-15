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
    void DFS(TreeNode* t, unordered_map<int, int>& freq) {
        if(!t)  return;
        DFS(t->left, freq);
        freq[t->val]++;
        DFS(t->right, freq);
    }
    vector<int> findMode(TreeNode* root) {
        if(!root)   return {};
        unordered_map<int, int> freq;
        DFS(root, freq);
        int max_count = 0;
        for(auto it : freq) {
            if(it.second > max_count)  max_count = it.second;
        }
        vector<int> result;
        for(auto it : freq) {
            if(it.second == max_count) result.push_back(it.first);
        }
        return result;
    }
};