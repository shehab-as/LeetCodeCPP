class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        if(nums.empty())    return {};
        vector<int> result;
        unordered_map<int, int> freq_count;
        for(int& e : nums)
            freq_count[e]++;
        priority_queue<pair<int,int>, vector<pair<int,int>>> pq;
        for(auto it : freq_count) {
            pq.push(make_pair(it.second, it.first));
            if(pq.size() > freq_count.size() - k) {
                result.push_back(pq.top().second);
                pq.pop();
            }
        }
        return result;
    }
};