class Solution {
public:
    string getPermutation(int n, int k) {
        vector<char> nums;
        int factorial = 1;
        for(int i = 1; i <= n; i++) {
            factorial *= i;
            nums.push_back(i + '0');
        }
        k--;
        string result;
        while(n) {
            factorial /= n;
            int digit = k / factorial;
            result.push_back(nums[digit]);
            nums.erase(nums.begin() + digit);
            n--;
            k %= factorial;
        }
        return result;
    }
};