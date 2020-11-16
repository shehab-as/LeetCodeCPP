class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.empty() || nums2.empty())  return {};
        vector<int> result;
        unordered_map<int, int> hmp;
        for(int& n : nums1)
            hmp[n]++;
        for(int& n : nums2) {
            if(--hmp[n] >= 0)
                result.push_back(n);
        }
        return result;
    }
};