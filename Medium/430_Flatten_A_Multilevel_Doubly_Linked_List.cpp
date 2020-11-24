/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        if(!head)   return NULL;
        Node* flatten_head = NULL;
        Node* curr = NULL, *prev = NULL;
        stack<Node*> stk;
        stk.push(head);
        while(!stk.empty()) {
            prev = curr;
            curr = stk.top();   stk.pop();
            if(curr->next)  stk.push(curr->next);
            if(curr->child) stk.push(curr->child);
            curr->child = NULL;
            curr->prev = prev;
            if(prev)    prev->next = curr;
            else    flatten_head = curr;
        }
        return flatten_head;
    }
};