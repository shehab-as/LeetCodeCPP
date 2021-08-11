class Solution {
public:
    bool canReorderDoubled(vector<int>& arr) {
        unordered_map<int, int> HashMap;
        for(int i = 0; i < arr.size(); i++) {
            HashMap[arr[i]]++;
        }
        sort(arr.begin(), arr.end(), [](int x, int y) {
            return abs(x) < abs(y);
        });
        for(int i = 0; i < arr.size(); i++) {
            if(HashMap[arr[i]] == 0) continue;
            if(HashMap[arr[i] * 2] <= 0) return false;
            HashMap[arr[i]]--;
            HashMap[arr[i] * 2]--;
        }
        return true;
    }
};