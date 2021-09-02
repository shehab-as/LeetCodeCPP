class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        if(nums.empty()) { return 0; }
        int N = nums.size();
        vector<bool> visited(N, false);
        int max_length = 0, curr_length;
        for(int& k : nums) {
            curr_length = 0;
            while(!visited[k]) {
                curr_length++;
                visited[k] = true;
                k = nums[k];
            }
            max_length = max(max_length, curr_length);
        }
        return max_length;
    }
};