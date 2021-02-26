class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int N = nums.size();
        unordered_map<int, int> hmp;
        int sum = 0; 
        hmp[0] = -1;
        int end = -1, len = 0;
        for(int i = 0; i < N; i++) {
            sum += (nums[i] == 0) ? -1 : 1;
            if(hmp.find(sum) != hmp.end()) {
                if(len < i - hmp[sum]) {
                    len = i - hmp[sum];
                    end = i;
                }
            }
            else
                hmp[sum] = i;
        }
        return len;
    }
};