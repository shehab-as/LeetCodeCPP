class Solution {
public:
    int findLucky(vector<int>& arr) {
        vector<int> Hmp(501, 0);
        int res = -1;
        for(int& ele : arr) {
            Hmp[ele]++;
        }
        for(int i = 1; i <= 500; i++) {
            res = max(res, Hmp[i] == i ? i : -1);
        }
        return res;
    }
};