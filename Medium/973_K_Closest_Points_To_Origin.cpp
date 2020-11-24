class Solution {
public:
    double EuclideanDistance(vector<int>& point) {
        return sqrt((point[0] * point[0]) + (point[1] * point[1]));
    }
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        vector<pair<double,vector<int>>> all_points;
        for(auto point : points) {
            double d = EuclideanDistance(point);
            all_points.push_back({d, point});
        }
        sort(all_points.begin(), all_points.end(), 
             [](const pair<double, vector<int>>& p1, const pair<double, vector<int>>& p2) {
                 return p1.first <= p2.first;
        });
        vector<vector<int>> result;
        for(int i = 0; i < K; i++)
            result.push_back(all_points[i].second);
        return result;
    }
};