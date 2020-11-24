class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
        int A_ptr = 0, B_ptr = 0;
        int NA = A.size(), NB = B.size();
        
        vector<vector<int>> result;
        
        while(A_ptr < NA && B_ptr < NB) {
            auto IntervalA = A[A_ptr];
            auto IntervalB = B[B_ptr];
            
            int begin_intersect = max(IntervalA[0], IntervalB[0]);  //left
            int end_intersect = min(IntervalA[1], IntervalB[1]);    //right
            
            if(begin_intersect <= end_intersect)
                result.push_back({begin_intersect, end_intersect});
            
            A_ptr += IntervalA[1] <= IntervalB[1] ? 1 : 0;
            B_ptr += IntervalB[1] <= IntervalA[1] ? 1 : 0;
        }
        
        return result;
    }
};