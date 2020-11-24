class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        vector<int> result(T.size());
        for(int i = T.size() - 1; i >= 0; i--) {
            int j = i + 1;
            while( j < T.size() && T[j] <= T[i]) {
                if(result[j] > 0)
                    j = result[j] + j;
                else
                    j = T.size();
            }
            if(j < T.size())
                result[i] = j - i;
        }
        return result;
    }
};

