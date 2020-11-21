/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    void DFS(Node* root) {
        if(!root || !root->left)
            return;
        DFS(root->left);
        DFS(root->right);
        Node* LeftChild = root->left;
        Node* RightChild = root->right;
        // cout<<"Pointing From Node: "<<LeftChild->val<<" To Node: "<<RightChild->val<<endl;
        LeftChild->next = RightChild;
        while(LeftChild->right) {
            LeftChild = LeftChild->right;
            RightChild = RightChild->left;
            // cout<<"Pointing From Node: "<<LeftChild->val<<" To Node: "<<RightChild->val<<endl;
            LeftChild->next = RightChild;
        }
        return;
    }
    Node* connect(Node* root) {
        DFS(root);
        return root;
    }
};

// Level-Order Traversal 
    // Node* connect(Node* root) {
    //     if(!root) {
    //         return nullptr;
    //     }
    //     queue<Node*> Q;
    //     Q.push(root);
    //     while(!Q.empty()) {
    //         int sz = Q.size();
    //         for(int i = 0; i < sz; i++) {
    //             Node* node = Q.front();
    //             Q.pop();
    //             if(i < sz - 1) {
    //                 node->next = Q.front();
    //             }
    //             if(node->left)  {
    //                 Q.push(node->left);
    //             }
    //             if(node->right) {
    //                 Q.push(node->right);
    //             }
    //         }
    //     }
    //     return root;
    // }