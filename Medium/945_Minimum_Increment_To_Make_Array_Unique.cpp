class Solution {
public:
    int minIncrementForUnique(vector<int>& A) {
        if(A.empty())   return 0;
        sort(A.begin(), A.end());
        int moves = 0, need = 0;
        for(int& a : A) {
            moves += max(need - a, 0);
            need = max(a, need) + 1;
        }
        return moves;
    }
};
