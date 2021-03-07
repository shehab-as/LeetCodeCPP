/*
// Definition for a Node.
class Node {
public:
    int val;
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
    vector<int> preorder(Node* root) {
        if(!root)   return {};
        vector<int> result;
        stack<Node*> s;
        s.push(root);
        while(!s.empty()) {
            Node *temp = s.top();
            s.pop();
            result.push_back(temp->val);
            for(int i=temp->children.size() - 1; i>=0; i--)
                s.push(temp->children[i]);
        }
        return result;
    }
};