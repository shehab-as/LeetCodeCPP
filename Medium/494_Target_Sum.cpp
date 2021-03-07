class Solution {
public:
    int DFS(vector<int>& nums, int S, int sum, int index)
    {
        if(index==nums.size())
            return (S==sum) ? 1 : 0;
        return DFS(nums, S, sum + nums[index], index+1) + 
            DFS(nums, S, sum - nums[index], index+1);
    }
    int findTargetSumWays(vector<int>& nums, int S) {
        return DFS(nums, S, 0, 0);
    }
};