/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {
private:
    stack<NestedInteger> stk;
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        for(auto i = nestedList.rbegin(); i != nestedList.rend(); i++) 
            stk.push(*i);    
    }
    
    int next() {
        auto my_top = stk.top();
        stk.pop();
        return my_top.getInteger();
    }
    
    bool hasNext() {
        while(!stk.empty()) {
            auto my_top = stk.top();
            if(my_top.isInteger())  return true;
            stk.pop();
            vector<NestedInteger> v = my_top.getList();
            for(auto i = v.rbegin(); i != v.rend(); i++)
                stk.push(*i);
            // if(stk.empty()) return false;
        }   
        return false;
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */