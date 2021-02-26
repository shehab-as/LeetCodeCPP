class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        vector<int> Copy;
        for(int& n : nums)
            Copy.push_back(n);
        for(int i = 0; i < nums.size(); i++)
            nums[(i + k) % nums.size()] = Copy[i];
    }
};
