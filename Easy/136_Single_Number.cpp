class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = 0;
        for_each(nums.begin(), nums.end(), [&res](const int& e) -> void { res ^= e; });
        return res;
    }
};