class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int start=-1, end=-2;
        int N = nums.size();
        int Mx = nums[0], Mn = nums[N-1];
        for(int i=0; i<N; i++) {
            Mx = max(nums[i], Mx);
            Mn = min(nums[N-i-1], Mn);
            
            if(nums[i] < Mx)
                end = i;
            if(nums[N-i-1] > Mn)
                start = N-i-1;
        }
        return end-start+1;
    }
};