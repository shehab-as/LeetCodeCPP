class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int count = 0;
        int curr_sum = 0;
        unordered_map<int, int> hmp;
        for(int e : nums) {
            curr_sum += e;
            count += curr_sum == k ? 1 : 0;
            if(hmp.find(curr_sum - k) != hmp.end())
                count += hmp[curr_sum - k];
            
            hmp[curr_sum]++;
        }
        return count;
    }
};