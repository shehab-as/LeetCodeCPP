class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if(intervals.empty())   return 0;
        sort(intervals.begin(), intervals.end(), [](const vector<int>& i1, const vector<int>& i2) {
            return i1[1] < i2[1];
        });
        int finishTime = intervals[0][1];
        int len = 1;
        for(int i = 1; i < intervals.size(); i++) {
            if(intervals[i][0] >= finishTime) {
                len++;
                finishTime = intervals[i][1];
            }
        }
        return intervals.size() - len;
    }
};