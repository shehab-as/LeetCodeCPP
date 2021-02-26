class RandomizedSet {
private:
    vector<int> A;
    unordered_map<int, int> HashMap;
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
        A.clear();
        HashMap.clear();
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if(HashMap.find(val) != HashMap.end())  return false;
        A.push_back(val);
        HashMap[val] = A.size() - 1;
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if(HashMap.find(val) == HashMap.end())  return false;
        int last_indx = A.size() - 1;
        int delete_indx = HashMap[val];
        int last_element = A[last_indx];
        swap(A[last_indx], A[delete_indx]);
        HashMap[last_element] = delete_indx;
        HashMap.erase(val);
        A.pop_back();
        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        int r = rand() % A.size();
        return A[r];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */