class NumArray {
private:
    vector<int> sums;
public:
    NumArray(vector<int>& nums) {
        int s = 0;
        for(int i = 0; i < nums.size(); i++) {
            s += nums[i];
            sums.push_back(s);
        }
    }
    
    int sumRange(int i, int j) {
        if(i==0)    return sums[j];
        return sums[j] - sums[i-1];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */