class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        unordered_map<int, int> hmp;
        int count = 0;
        for(auto& t : time) {
            int d = t % 60;
            count += (d == 0) ? hmp[d] : hmp[60 - d];
            hmp[d]++;
        }
        return count;
    }
};