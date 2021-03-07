class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int total_time = 0, diff;
        if(timeSeries.size() == 0)  return 0;
        for(int i=0; i<timeSeries.size() - 1; i++)
        {
            diff = timeSeries[i+1] - timeSeries[i];
            (diff < duration) ? total_time += diff : total_time += duration;
        }
        total_time += duration;      // last time frame
        return total_time;
    }
};