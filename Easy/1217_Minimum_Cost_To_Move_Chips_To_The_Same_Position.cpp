class Solution {
public:
    int minCostToMoveChips(vector<int>& chips) {
        int even = count_if(chips.begin(), chips.end(), [](const int& e){return e%2 == 0;});
        int odd = chips.size() - even;
        return min(even, odd);
    }
};