class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        unordered_set<int> used;
        sort(nums.begin(), nums.end());
        int unique_pairs = 0;
        for(int i = 0; i < nums.size() - 1; i++) {
            for(int j = i + 1; j < nums.size(); j++) {
                int num1 = nums[i], num2 = nums[j];
                if(abs(num1-num2) == k && 
                   ( used.find(num1) == used.end() || used.find(num2) == used.end())) {
                    unique_pairs++;
                    used.insert(num1);
                    used.insert(num2);
                }
            }
        }
        return unique_pairs;
    }
};