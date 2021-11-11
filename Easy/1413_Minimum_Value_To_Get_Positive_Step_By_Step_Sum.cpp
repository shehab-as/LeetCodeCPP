class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int startValue = 1;
        bool foundMinimum = false;
        while (!foundMinimum) {
            int currStartValue = startValue;
            int count = 0;
            for(int& num : nums) {
                if(currStartValue + num < 1) {
                    startValue++;
                    break;
                } 
                else {
                    currStartValue = currStartValue + num;
                    count++;
                }
            }
            if(count == nums.size()) { foundMinimum = true; }
        }
        return startValue;
    }
};
