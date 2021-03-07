/*
// Definition for a Node.
class Node {
public:
    int val = NULL;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        if(!root)
            return {};
        vector<vector<int>> res;
        queue<Node*> q;
        q.push(root);
        while(!q.empty()) {
            vector<int> level;
            int sz = q.size();
            for(int i=0; i<sz; i++) {
                Node* temp = q.front();
                q.pop();
                level.push_back(temp->val);
                for(auto &child : temp->children)
                    if(child)
                        q.push(child);
            }
            res.push_back(level);
        }
        return res;
    }
};