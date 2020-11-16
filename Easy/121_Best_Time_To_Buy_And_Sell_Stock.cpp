class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int lowest = INT_MAX;
        int maximum = 0;
        for(int i = 1; i < prices.size(); i++) {
            if(prices[i] - prices[i-1] > 0)
                lowest = min(lowest, prices[i-1]);
            maximum = max(maximum, prices[i] - lowest);
        }
        return maximum;
    }
};