class RandomizedCollection {
private:
    vector<pair<int,int>> A;
    unordered_map<int, vector<int>> keysTable;
public:
    /** Initialize your data structure here. */
    RandomizedCollection() {
        A.clear();
        keysTable.clear();
    }
    
    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) {
        bool flag = keysTable.find(val) == keysTable.end();
        keysTable[val].push_back(A.size());
        A.push_back({val, keysTable[val].size() - 1});
        return flag;
    }
    
    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val) {
        if(keysTable.find(val) == keysTable.end()) {
            return false;
        }
        auto last = A.back();
        keysTable[last.first][last.second] = keysTable[val].back();
        A[keysTable[val].back()] = last;
        keysTable[val].pop_back();
        // cleanup
        if(keysTable[val].empty()) {
            keysTable.erase(val);
        }
        A.pop_back();
        return true;
    }
    
    /** Get a random element from the collection. */
    int getRandom() {
        int random_key = rand() % A.size();
        return A[random_key].first;
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */