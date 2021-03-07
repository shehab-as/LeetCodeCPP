class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& nums) {
        vector<string> ranks;
        bool top_3[3] = {false, false, false};
        if(nums.size() < 1) return {};
        vector<int> sorted_nums = nums;
        sort(sorted_nums.begin(), sorted_nums.end());
        unordered_map<int, string> hmp;
        int pos = 4;
        for(int i=sorted_nums.size()-1; i>=0; i--) {
            if(!top_3[0]) {
                hmp[sorted_nums[i]] = "Gold Medal";
                top_3[0] = true;
            }
            else if(!top_3[1]) {
                hmp[sorted_nums[i]] = "Silver Medal";
                top_3[1] = true;
            }
            else if(!top_3[2]) {
                hmp[sorted_nums[i]] = "Bronze Medal";
                top_3[2] = true;
            }
            else {
                hmp[sorted_nums[i]] = to_string(pos);
                pos++;
            }
        }
        vector<string> result;
        for(int &value : nums) 
            result.push_back(hmp[value]);
        return result;
    }
};