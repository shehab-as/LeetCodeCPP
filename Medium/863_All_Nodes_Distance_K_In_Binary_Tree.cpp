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
    void DFS(TreeNode* root, TreeNode* target, unordered_map<TreeNode*, TreeNode*>& BackEdge) {
        if(!root || (target == root))   return;
        if(root->left) {
            BackEdge[root->left] = root;
            DFS(root->left, target, BackEdge);
        }
        if(root->right) {
            BackEdge[root->right] = root;
            DFS(root->right, target, BackEdge);
        }
        
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        unordered_map<TreeNode*, TreeNode*> BackEdge;
        unordered_set<TreeNode*> visited;
        vector<int> res;
        DFS(root, target, BackEdge);
        queue<TreeNode*> que;
        que.push(target);
        while(!que.empty() && K >= 0) {
            int sz = que.size();
            for(int i = 0; i < sz; i++) {
                TreeNode* curr = que.front();   
                que.pop();
                visited.insert(curr);
                if(K == 0)  res.push_back(curr->val);
                if(!visited.count(BackEdge[curr]) && BackEdge[curr])    que.push(BackEdge[curr]);
                if(!visited.count(curr->left) && curr->left)    que.push(curr->left);
                if(!visited.count(curr->right) && curr->right)  que.push(curr->right);
            }
            K--;
        }
        return res;
    }
};