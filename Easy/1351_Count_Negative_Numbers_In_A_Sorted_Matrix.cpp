class Solution {
public:
    int BinarySearch(const vector<int>& row) {
        int N = row.size();
        int start = 0, end = N - 1;
        while(start <= end) {
            int mid = start + (end - start) / 2;
            if (row[mid] >= 0) {
                start = mid + 1;
            }
            else {
                end = mid - 1;
            }
        }
        return N - start;
    }
    int countNegatives(vector<vector<int>>& grid) {
        int total_negatives = 0;
        for(auto row : grid) {
            // cout<<"Number of Negatives -> "<<BinarySearch(row)<<endl;
            total_negatives += BinarySearch(row);
        }
        return total_negatives;
    }
};
