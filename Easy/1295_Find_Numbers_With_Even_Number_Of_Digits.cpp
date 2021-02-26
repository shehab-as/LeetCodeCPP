class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int even_no = 0;
        int digit_count;
        for(int& n : nums) {
            digit_count = 0;
            while(n) {
                digit_count++;
                n /= 10;
            }
            if(digit_count % 2 == 0)
                even_no++;
        }
        return even_no;
    }
};