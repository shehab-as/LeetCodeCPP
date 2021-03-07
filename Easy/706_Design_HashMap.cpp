class MyHashMap {
private:
    static const int MAX_SIZE = 1000001;
    int A[MAX_SIZE];
public:
    /** Initialize your data structure here. */
    MyHashMap() {
        for(int i = 0; i < MAX_SIZE; i++) {
            A[i] = INT_MIN;
        }
    }
    
    /** value will always be non-negative. */
    void put(int key, int value) {
        A[key] = value;
    }
    
    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        if(A[key] != INT_MIN) {
            return A[key];
        }
        return -1;
    }
    
    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        A[key] = INT_MIN;
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */