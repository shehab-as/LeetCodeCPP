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
class BSTIterator {
private:
    stack<TreeNode*> Stk;
    
    void AddLeftChildren(TreeNode* node) {
        while(node) {
            Stk.push(node);
            node = node->left;
        }
    }
public:
    BSTIterator(TreeNode* root) {
        AddLeftChildren(root);
    }
    
    int next() {
        if(!hasNext())  
            return -1;
        TreeNode* node = Stk.top();
        Stk.pop();
        if(node->right)
            AddLeftChildren(node->right);
        return node->val;
    }
    
    bool hasNext() {
        return Stk.size() > 0;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */