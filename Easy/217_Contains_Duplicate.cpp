class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> elements;
        for(int& n : nums) {
            if(elements.find(n) != elements.end())
                return true;
            elements.insert(n);
        }
        return false;
    }
};