class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        if(arr.empty()) return {};
        vector<int> res (arr.size(), -1);
        int max_val = arr[arr.size() - 1];
        for(int i = arr.size() - 2; i >= 0; i--) {
            res[i] = max_val;
            max_val = max(max_val, arr[i]);
        }
        return res;
    }
};