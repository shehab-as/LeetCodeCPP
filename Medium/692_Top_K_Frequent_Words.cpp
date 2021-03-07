struct cmp {
    bool operator()(pair<int, string> &a, pair<int, string> &b) {
        if(a.first == b.first)
            return a.second > b.second;
        return a.first < b.first;
    }
};
class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> word_to_freq;
        for(string &word : words)
            word_to_freq[word]++;
        priority_queue<pair<int, string>, vector<pair<int, string>>, cmp> heap;
        for(auto &key_val : word_to_freq)
            heap.push(make_pair(key_val.second, move(key_val.first)));
        vector<string> res;
        res.reserve(k);
        for(int i=0; i<k; i++) {
            res.push_back(move(heap.top().second));
            heap.pop();
        }
        return res;
    }
};
