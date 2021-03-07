class MyQueue {
    stack<int> s;
public:
    /** Initialize your data structure here. */
    MyQueue() {
        
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        s.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        vector<int> v;
        int element;
        while(!s.empty()) {
            element = s.top();
            s.pop();
            if(s.empty())
                break;
            v.push_back(element);
        }
        for(int i=v.size()-1; i>=0; i--)
            s.push(v[i]);
        return element;
    }
    
    /** Get the front element. */
    int peek() {
        stack<int> temp = s;
        int last;
        while(true) {
            last = temp.top();
            temp.pop();
            if(temp.empty())
                break;
        }
        return last;
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return s.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue obj = new MyQueue();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.peek();
 * bool param_4 = obj.empty();
 */