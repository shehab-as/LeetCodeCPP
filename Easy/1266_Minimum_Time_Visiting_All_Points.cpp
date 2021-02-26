class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int total_time = 0;
        for(int i = 0; i < points.size() - 1; i++) {
            auto point1 = points[i];
            auto point2 = points[i+1];
            int dx = abs(point1[0] - point2[0]);
            int dy = abs(point1[1] - point2[1]);
            total_time += max(dx, dy);
        }
        return total_time;
    }
};