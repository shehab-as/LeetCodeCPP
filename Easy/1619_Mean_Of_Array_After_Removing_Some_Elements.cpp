class Solution {
public:
    double trimMean(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int N = arr.size();
        int shift = round(N * 0.05);
        double total = 0;
        for(int i = shift; i < N - shift; i++) {
            total += arr[i];
        }
        return total / (N - 2*shift);
    }
};