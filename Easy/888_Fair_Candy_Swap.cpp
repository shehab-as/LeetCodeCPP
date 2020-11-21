class Solution {
public:
    int getTotal(vector<int> V) {
        int total = 0;
        for(int &e : V) total += e;
        return total;
    }
    vector<int> fairCandySwap(vector<int>& A, vector<int>& B) {
        int totalA = getTotal(A), totalB = getTotal(B);
        unordered_map<int, int> HashMap;
        for(int j = 0; j < B.size(); j++) {
            HashMap.insert({totalB - 2 * B[j], B[j]});
        }
        //totalA - 2A[i] = totalB - 2B[j]
        for(int i = 0; i < A.size(); i++) {
            unordered_map<int,int>::iterator it = HashMap.find(totalA - 2 * A[i]);
            if(it != HashMap.end()) {
                return {A[i], it->second};
            }
        }
        return {-1, -1};
    }
};

