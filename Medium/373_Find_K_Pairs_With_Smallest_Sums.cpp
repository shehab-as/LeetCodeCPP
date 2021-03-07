struct comp {
    bool operator()(pair<int,int> a, pair<int,int> b) {
        return (a.first + a.second) < (b.first + b.second); 
    }
} comp;
class Solution {
public:

    vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        if(!nums1.size() && !nums2.size())
            return {};
        vector<pair<int, int>> k_smallest;
        for(int i=0; i<nums1.size(); i++) {
            for(int j=0; j<nums2.size(); j++) {
                k_smallest.push_back(make_pair(nums1[i], nums2[j]));
            }
        }
        sort(k_smallest.begin(), k_smallest.end(), comp);
        if(k_smallest.size() <= k)
            return k_smallest;
        k_smallest.erase(k_smallest.begin()+k, k_smallest.end());
        return k_smallest;
    }
};