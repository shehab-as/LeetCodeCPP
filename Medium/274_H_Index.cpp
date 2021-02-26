class Solution {
public:
    int hIndex(vector<int>& citations) {
        const int N = citations.size();
        vector<int> buckets(N+1, 0);
        for(int i = 0; i < N; i++) {
            buckets[min(citations[i], N)]++;
        }
        int total_papers = 0;
        for(int i = N ; i >= 0; i--) {
            total_papers += buckets[i];
            if(total_papers >= i)   return i;
        }
        return 0;
    }
};