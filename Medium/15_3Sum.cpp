class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        int N = nums.size();
        sort(nums.begin(), nums.end());
        for(int i = 0; i < N; i++) {
            int target = -nums[i];
            int front = i + 1;
            int back = N - 1;
            while (front < back) {
                int sum = nums[front] + nums[back];
                if (sum < target)
                    front++;
                else if(sum > target)
                    back--;
                else {
                    vector<int> combination = {nums[i],nums[front],nums[back]};
                    result.push_back(combination);
                    // Processing duplicates of number 2.
                    while (front < back && nums[front] == combination[1]) 
                        front++;
                    // Provessing duplicates of number 3.
                    while (front < back && nums[back] == combination[2])    
                        back--;
                }
            }
            while( i + 1 < N && nums[i + 1] == nums[i])
                i++;
        }
        return result;
    }
};