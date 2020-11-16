class Solution {
public:
    bool rotateString(string A, string B) {
        if(A == B)  return true;
        for(int i = 0; i < A.length(); i++) {
            char c = A[0];
            A.erase(A.begin());
            A += c;
            if(A == B)  return true;
        }
        return false;
    }
};