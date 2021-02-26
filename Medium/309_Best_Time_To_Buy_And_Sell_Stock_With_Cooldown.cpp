class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.empty())  return 0;
        int S1 = 0, S2 = -prices[0], S3 = 0;
        for(int& price : prices) {
            int prevS1 = S1;
            S1 = max(S1, S3);
            S3 = S2 + price;
            S2 = max(S2, prevS1 - price);
        }
        return max(S1, S3);
    }
};