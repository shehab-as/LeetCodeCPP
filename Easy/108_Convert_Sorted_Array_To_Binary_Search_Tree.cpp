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
    void createBST(TreeNode *& root, const vector<int>& nums, int low, int high) {
        if(low >= high) return;
        int middle = low + (high - low) / 2;
        root = new TreeNode(nums[middle]);
        createBST(root->left, nums, low, middle);
        createBST(root->right, nums, middle + 1, high);
    }
        
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(nums.empty())    return NULL;
        TreeNode* root;
        createBST(root, nums, 0, nums.size());
        return root;
    }
};