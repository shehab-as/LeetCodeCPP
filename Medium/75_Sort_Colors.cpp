class Solution {
public:
    void sortColors(vector<int>& nums) {
        int r = 0, w = 0, b = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == 2)
                nums[b++] = 2;
            if(nums[i] == 1) {
                nums[b++] = 2;
                nums[w++] = 1;
            }
            if(nums[i] == 0) {
                nums[b++] = 2;
                nums[w++] = 1;
                nums[r++] = 0;
            }
        }
        // for(int n : nums) {
        //     r += n == 0 ? 1 : 0;
        //     w += n == 1 ? 1 : 0;
        //     b += n == 2 ? 1 : 0;
        // }
        // for(int i = 0; i < nums.size(); i++) {
        //     while(r) {
        //         nums[i++] = 0;
        //         r--;
        //     }
        //     while(w) {
        //         nums[i++] = 1;
        //         w--;
        //     }
        //     while(b) {
        //         nums[i++] = 2;
        //         b--;
        //     }
        // }
    }
};
