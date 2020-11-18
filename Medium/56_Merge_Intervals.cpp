class Solution {
public:
    struct IntervalSort {
        bool operator()(const vector<int>& i1, const vector<int>& i2) {
            return i1[0] < i2[0];
        }
    };
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(intervals.empty())   return {};
        sort(intervals.begin(), intervals.end(), IntervalSort());
        vector<vector<int>> res;
        res.push_back(intervals[0]);
        int j = 0;
        for(int i = 1; i < intervals.size() && j < intervals.size(); i++) {
            if(intervals[i][0] <= res[j][1]) {
                res[j][1] = max(res[j][1], intervals[i][1]);
            }
            else {
                res.push_back(intervals[i]);
                j++;
            }
        }
        return res;
    }
};