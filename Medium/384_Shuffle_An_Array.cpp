class Solution {
private:
    vector<int> A;
    vector<int> reset_nums;
public:
    Solution(vector<int>& nums) {
        for(int& e : nums) {
            A.push_back(e);
            reset_nums.push_back(e);
        }
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return reset_nums;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        for(int i = 0; i < A.size(); i++) {
            int j = rand() % A.size();
            swap(A[i], A[j]);
        }
        return A;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */