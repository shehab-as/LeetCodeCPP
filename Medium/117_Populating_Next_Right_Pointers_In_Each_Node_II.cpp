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
    Node* connect(Node* root) {
        Node* node = root;
        Node* levelhead = new Node(0);
        while(node) {
            Node* needle = levelhead;
            
            while(node) {
                if(node->left) {
                    needle->next = node->left;
                    needle = needle->next;
                }
                if(node->right) {
                    needle->next = node->right;
                    needle = needle->next;
                }
                node = node->next;
            }
            
            node = levelhead->next;
            levelhead->next = nullptr;
        }
        return root;
    }
};