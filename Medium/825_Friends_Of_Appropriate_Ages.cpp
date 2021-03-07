class Solution {
public:
    bool canAdd(int A, int B) {
        return !((B <= 0.5*A + 7) || (B > A) || (B > 100 && A < 100));
    }
    int numFriendRequests(vector<int>& ages) {
        unordered_map<int, int> hmp;
        for(int& age : ages)
            hmp[age]++;
        int requests = 0;
        for(auto& A : hmp) {
            for(auto& B : hmp) {
                if(canAdd(A.first, B.first))
                    requests += A.second * (B.second - ((A.first == B.first) ? 1 : 0));
            }
        }
        return requests;
    }
};