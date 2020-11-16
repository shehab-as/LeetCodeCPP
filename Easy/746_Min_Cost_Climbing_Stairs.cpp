class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> memo(cost.size(), INT_MAX);
        memo[0] = cost[0];
        memo[1] = cost[1];
        for(int i = 2; i < cost.size(); i++) {
            memo[i] = cost[i] + min(memo[i-1], memo[i-2]);
        }
        return min(memo[cost.size()-1], memo[cost.size()-2]);
    }
};