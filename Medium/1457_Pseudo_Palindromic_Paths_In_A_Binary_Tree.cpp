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

    void DFS(TreeNode* root, unordered_map<int, int>& hmp, int& count) {
        if(!root)   return;
        if(root->left == root->right) {
            hmp[root->val]++;
            // CHECK PALINDROME PATH
            bool odd = false;
            bool palindrome = true;
            for(auto it : hmp) {
                if(it.second == 0)  continue;
                if(it.second % 2 == 1 && odd)   palindrome = false;
                if(it.second % 2)   odd = true;
            }
            count += palindrome ? 1 : 0;
            hmp[root->val]--;
            return;
        }
        
        hmp[root->val]++;
        DFS(root->left, hmp, count);
        hmp[root->val]--;
        
        hmp[root->val]++;
        DFS(root->right, hmp, count);
        hmp[root->val]--;
    }
    
    int pseudoPalindromicPaths (TreeNode* root) {
        int count = 0;
        unordered_map<int, int> hmp;
        DFS(root, hmp, count);

        return count;
    }
};