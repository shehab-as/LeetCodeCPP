class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        size_t max_size = 0;
        bool visited[nums.size()] = {false};
        for(int i = 0; i < nums.size(); i++) {
            size_t size = 0;
            while(!visited[nums[i]]) {
                size++;
                visited[nums[i]] = true;
                nums[i] = nums[nums[i]];
            }
            max_size = max(max_size, size);
        }
        return max_size;
    }
};