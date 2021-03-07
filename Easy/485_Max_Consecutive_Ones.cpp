class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int curMax = 0, res = 0;
        for(auto num : nums){
            if (num) 
                curMax++;
            else {
                res = max(curMax, res);
                curMax = 0;
            }  
        }
        return max(curMax,res);
    }
};