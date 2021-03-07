class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> s;
        unordered_map<int, int> hmp;
        vector<int> res;
        if(nums1.size() == 0 || nums2.size() == 0)
            return {};
        for(int i=0; i<nums1.size(); i++)
            hmp[nums1[i]]++;
        
        for(int j=0; j<nums2.size(); j++)
        {
            if(hmp[nums2[j]])
                s.insert(nums2[j]);
        }
        for(auto it = s.begin(); it != s.end(); it++)
            res.push_back(*it);

        return res;
    }
};