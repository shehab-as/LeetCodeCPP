class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        if(nums.empty())    return 0;
        int left = 0, right = 0;
        int sum = 0, len = INT_MAX;
        while(right < nums.size()) {
            sum += nums[right++];
            while(sum >= s) {
                len = min(len, right - left);
                sum -= nums[left++];
            }
        }
        return len == INT_MAX ? 0 : len;
    }
};

    // int minSubArrayLen(int s, vector<int>& nums) {
    //     if(nums.empty())    return 0;
    //     int curr_min_len = INT_MAX;
    //     for(int i = 0; i < nums.size(); i++) {
    //         int sum = 0;
    //         for(int j = i; j < nums.size(); j++) {
    //             sum += nums[j];
    //             if(sum >= s) {
    //                 curr_min_len = min(curr_min_len, (j - i + 1));
    //                 break;
    //             }
    //         }
    //     }
    //     return (curr_min_len == INT_MAX) ? 0 : curr_min_len;
    // }