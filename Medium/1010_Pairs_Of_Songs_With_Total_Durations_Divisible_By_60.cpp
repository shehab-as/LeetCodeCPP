class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        if(time.empty()) {
            return 0;
        }
        unordered_map<int, int> HashMap;
        int count = 0;
        for(int& t : time) {
            int rem = (60 - t % 60) % 60;
            count += HashMap[rem];
            HashMap[t % 60]++;
        }
        return count;
    }
};