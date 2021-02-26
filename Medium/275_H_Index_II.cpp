class Solution {
public:
    int hIndex(vector<int>& citations) {
        int N = citations.size();
        int low = 0, high = N - 1;
        while(low <= high) {
            int mid = low + (high-low) / 2;
            int h = citations[mid];
            if(h >= (N - mid)) 
                high = mid - 1;
            else 
                low = mid + 1;
        }
        return N - low;
    }
};