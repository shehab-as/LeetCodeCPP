class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int N = (int) nums.size();
        int closest = nums[0] + nums[1] + nums[2];
        for(int first = 0; first < N - 2; first++) {
            if(first > 0 && nums[first] == nums[first-1])    
                continue;
            int second = first + 1;
            int third = N - 1;
            while(second < third) {
                int currSum = nums[first] + nums[second] + nums[third];
                if(currSum == target)   return currSum;
                if(abs(closest - target) > abs(currSum - target)) {
                    closest = currSum;
                }
                if(currSum > target) {
                    third--;
                } else {
                    second++;
                }
            }
        }
        return closest;
    }
};