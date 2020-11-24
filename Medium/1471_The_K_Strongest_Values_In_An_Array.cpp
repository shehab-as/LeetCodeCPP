class Solution {
public:
    vector<int> getStrongest(vector<int>& arr, int k) {
        sort(arr.begin(), arr.end());
        int N = arr.size();
        int m = arr[(N-1)/2];
        vector<pair<int,int>> result;
        for(int& e : arr) {
            result.push_back({e, abs(e-m)});
        }
        sort(result.begin(), result.end(), 
             [](const pair<int,int>&p1, const pair<int,int>&p2) {
                 return p1.second > p2.second || 
                     (p1.second == p2.second && p1.first > p2.first);
             });
        vector<int> final_result(k, -1);
        for(int i = 0; i < k; i++) {
            final_result[i] = result[i].first;
        }
        return final_result;
    }
};