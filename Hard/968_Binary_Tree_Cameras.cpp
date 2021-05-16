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
private:
    int total_cameras = 0;
    enum {
        NOT_NEEDED = -1,
        NO_CAMERA = 0,
        HAS_CAMERA = 1
    };
    int DFS(TreeNode* root) {
        if(!root) {
            return NOT_NEEDED;
        }
        int left = DFS(root->left);
        int right = DFS(root->right);
        if(left == NO_CAMERA || right == NO_CAMERA) {
            total_cameras++;
            return HAS_CAMERA;
        }
        else if (left == HAS_CAMERA || right == HAS_CAMERA) {
            return NOT_NEEDED;
        }
        else {
            return NO_CAMERA;
        }
    }
public:
    
    int minCameraCover(TreeNode* root) {
        if(DFS(root) == NO_CAMERA) {
            total_cameras++;
        }
        return total_cameras;
    }
};