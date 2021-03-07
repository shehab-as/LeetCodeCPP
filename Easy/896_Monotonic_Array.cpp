class Solution {
public:
    bool isMonotonic(vector<int>& A) {
        if(A.size()==1)
            return true;
        bool increase;
        int first = A[0];
        int last = A[A.size()-1];
        (first<=last) ? increase = true : increase = false;
        for(int i=0; i<A.size()-1; i++)
        {
            if(A[i] < A[i+1] && !increase)
                return false;
            if(A[i] > A[i+1] && increase)
                return false;
        }
        return true;
    }
};