class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int first_single = 0, second_single = 0;
        int AB = 0;
        for(int &n : nums)
            AB ^= n;
        int diff = AB & -(AB);
        for(int &n : nums) {
            if((diff & n) == 0)
                first_single ^= n;
            else
                second_single ^= n;
        }
        return {first_single, second_single};
    }
};
