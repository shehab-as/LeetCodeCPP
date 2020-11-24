class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int N = costs.size();
        vector<pair<int,int>> cost_diff;
        int minimal_cost = 0;
        for(int i = 0; i < N; i++) {
            cost_diff.push_back({costs[i][0]-costs[i][1], i});
        }
        sort(cost_diff.begin(), cost_diff.end());

        for(int i = 0; i < N/2; i++)
            minimal_cost += costs[cost_diff[i].second][0];

        for(int i = N/2; i < N; i++)
            minimal_cost += costs[cost_diff[i].second][1];
        
        return minimal_cost;
    }
};