class Solution {
public:
    bool buddyStrings(string A, string B) {
        if (A.empty() || A.length() != B.length())   return false;
        unordered_map<char, int> hmp1;
        for(char &c : A)
            hmp1[c]++;
        bool more_than_one = false;
        for(auto it : hmp1)
            if(it.second > 1)
                more_than_one = true;
        int diff = 0;
        int indx1, indx2;
        for(int i = 0; i < A.length(); i++) {
            if(A[i] != B[i]) {
                if(diff == 0)   indx1 = i;
                else if (diff == 1) indx2 = i;
                else return false;
                diff++;
            }
        }
        if(diff > 1)
            swap(A[indx1], A[indx2]);
        return (A == B && diff == 0 && more_than_one) || (A==B && diff == 2);
    }
};