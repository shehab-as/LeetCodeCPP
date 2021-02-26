class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int single = 0;
        for(int i = 0; i < 32; i++) {
            int countOne = 0;
            for(int& e : nums)
                countOne += (e >> i) & 1;
            single += (countOne % 3) << i;
        }
        return single;
    }
};