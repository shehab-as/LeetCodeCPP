class Solution {
private:
    vector<int> weights;
    vector<int> prefix;
    int N;
    int sum = 0;
public:
    Solution(vector<int>& w) : weights(w) {
        N = weights.size();
        for(int i = 0; i < N; i++) {
            sum += weights[i];
            prefix.push_back(sum);
        }   
    }
    
    int pickIndex() {
        int r = (rand() % prefix.back()) + 1;   // 0 - SumOfWeights
        // cout<<"SumOfWeights: "<<prefix[N-1]<<endl;
        // cout<<"RandomNumber: "<<r<<endl;
        int low = 0, high = N - 1;
        while( low <= high ) {
            int mid = low + (high - low) / 2;
            (r > prefix[mid]) ? low = mid + 1 : high = mid - 1;
        }
        return low;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */