class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        int orig_r = nums.size();
        int orig_c = nums[0].size();
        if( (r*c) != (orig_r*orig_c) )
            return nums;
        vector<int> flattened(r*c);
        for(int i=0; i<orig_r; i++) 
            for(int j=0; j<orig_c; j++)
                flattened[i*orig_c + j] = nums[i][j];
        vector<vector<int>> reshaped (r, vector<int>(c));
        int k = 0;
        for(int i = 0; i<r; i++) {
            for(int j = 0; j<c; j++) {
                reshaped[i][j] = flattened[k++];
            }
        }
        return reshaped;
    }
};