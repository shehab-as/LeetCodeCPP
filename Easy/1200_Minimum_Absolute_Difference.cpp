class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        vector<vector<int>> result;
        int abs_min = INT_MAX;
        for(int i = 0; i < arr.size() - 1; i++) {
            int curr_min = arr[i+1] - arr[i];
            abs_min = min(abs_min, curr_min);
        }
        for(int i = 0; i < arr.size() - 1; i++) {
            int curr_min = arr[i+1] - arr[i];
            if(curr_min == abs_min)
                result.push_back({arr[i], arr[i+1]});
        }
        return result;
    }
};