class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int N = nums.size();
        vector<int> divCount(N, 0);
        vector<int> prev(N, 0);
        sort(nums.begin(), nums.end());
        int max_val = 0, index = -1;
        for(int i = 0; i < N; i++) {
            divCount[i] = 1;
            prev[i] = -1;
            for(int j = i - 1; j >= 0; j--) {
                if(nums[i] % nums[j] == 0) {
                    if(1 + divCount[j] > divCount[i]) {
                        divCount[i] = divCount[j] + 1;
                        prev[i] = j;
                    }
                }
            }
            if(divCount[i] > max_val) {
                max_val = divCount[i];
                index = i;
            }
        }
        vector<int> result;
        while(index != -1) {
            result.push_back(nums[index]);
            index = prev[index];
        }
        return result;
    }
};
