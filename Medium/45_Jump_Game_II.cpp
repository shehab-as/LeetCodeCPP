class Solution {
public:
    int jump(vector<int>& nums) {
        if(nums.size() <= 1)    return 0;
        int currIndex = (int) nums.size() - 1;
        int steps = 0;
        while(currIndex != 0) {
            for(int i = 0; i < currIndex; i++) {
                if(nums[i] >= currIndex - i) {
                    currIndex = i;
                    steps++;
                    break;
                }
            }
        }
        return steps;
    }
};