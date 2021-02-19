class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        if(accounts.empty() || accounts[0].empty()) return 0;
        int global_wealth = 0;
        for(int customer = 0; customer < accounts.size(); customer++) {
            int current_wealth = 0;
            for(int bank = 0; bank < accounts[0].size(); bank++) {
                current_wealth += accounts[customer][bank];
            }
            global_wealth = max(global_wealth, current_wealth);
        }
        return global_wealth;
    }
};