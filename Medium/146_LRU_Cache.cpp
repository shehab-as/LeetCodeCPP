class LRUCache {
private:
    int MAX_C;
    list<pair<int,int>> cache;
    unordered_map<int, list<pair<int,int>>::iterator> hmp;
public:
    LRUCache(int capacity) : MAX_C(capacity) {
        
    }
    
    int get(int key) {
        auto it = hmp.find(key);
        if(it == hmp.end()) { return -1; }
        cache.splice(cache.begin(), cache, it->second);
        return it->second->second;
    }
    
    void put(int key, int value) {
        auto it = hmp.find(key);
        if(it != hmp.end()) {
            cache.splice(cache.begin(), cache, it->second);
            it->second->second = value;
            return;
        }
        if(hmp.size() == MAX_C) {
            int key_remove = cache.back().first;
            cache.pop_back();
            hmp.erase(key_remove);
        }
        cache.push_front({key, value});
        hmp[key] = cache.begin();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */