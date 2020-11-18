class MyLinkedList {
private:
    struct Node {
        int val;
        Node* next;
        Node(const int& p_val) : val(p_val), next(nullptr) {}
    };
    Node* head;
    int len;
public:
    /** Initialize your data structure here. */
    MyLinkedList() : head(nullptr), len(0) {}
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        if(index >= len) {
            return -1;
        }
        Node* runner = head;
        while(index) {
            runner = runner->next;
            index--;
        }
        return runner->val;
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        len++;
        Node* node = new Node(val);
        if(!head) {
            head = node;
            return;
        }
        node->next = head;
        head = node;
        return;
        
    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        Node* node = new Node(val);
        len++;
        if(!head) {
            head = node;
            return;
        }
        Node* runner = head;
        while(runner->next) {
            runner = runner->next;
        }
        runner->next = node;
    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        if(index > len) {
            return;
        }
        if(index == 0) {
            addAtHead(val);
            return;
        }
        if(index == len) {
            addAtTail(val);
            return;
        }
        Node* runner = head;
        Node* prev = nullptr;
        Node* node = new Node(val);
        while(index) {
            prev = runner;
            runner = runner->next;
            index--;
        }
        prev->next = node;
        node->next = runner;
        len++;
        return;
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        if(index >= len) {
            return;
        }
        if(index == 0) {
            Node* current = head->next;
            delete head;
            head = current;
            len--;
            return;
        }
        Node* runner = head;
        Node* prev = nullptr;
        while(index) {
            prev = runner;
            runner = runner->next;
            index--;
        }
        prev->next = runner->next;
        runner->next = nullptr;
        delete runner;
        len--;
        return;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */