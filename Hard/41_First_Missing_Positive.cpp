class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        unordered_set<int> hashset;
        int sz = nums.size();
        for(int& e : nums)
            hashset.insert(e);
        int smallest = 1;
        while(sz) {
            if(hashset.find(smallest) != hashset.end()) 
                smallest++;
            sz--;
        }
        return smallest;
    }
};