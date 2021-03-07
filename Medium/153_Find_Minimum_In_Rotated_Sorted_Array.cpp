class Solution {
public:
    int findMin(vector<int>& nums) {
        if(nums.empty())    return 0;
        int smallest = INT_MAX;
        for(int& x : nums)
            smallest = min(x, smallest);
        return smallest;
    }
};