class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& A) {
        int maximum_score = INT_MIN;
        int i = 0;
        for(int j=1; j<A.size(); j++) {
            maximum_score = max(maximum_score, (A[i] + A[j]) + (i - j));
            if (A[j] + j >= A[i] + i)
                i = j;
        }
        return maximum_score;
    }
};