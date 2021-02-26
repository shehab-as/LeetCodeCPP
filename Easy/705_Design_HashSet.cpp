class MyHashSet {
private:
    vector<int> Array;
public:
    /** Initialize your data structure here. */
    MyHashSet() {
        Array.resize(1000000, -1);
    }
    
    void add(int key) {
        Array[key] = key;
    }
    
    void remove(int key) {
        Array[key] = -1;
    }
    
    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        return Array[key] == -1 ? false : true;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */