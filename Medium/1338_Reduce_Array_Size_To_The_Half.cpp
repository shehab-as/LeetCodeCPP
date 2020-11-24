class Solution {
public:
    int minSetSize(vector<int>& arr) {
        int N = arr.size();
        unordered_map<int, int> hmp;
        vector<int> vs;       
        int count = 0;
        for(int e : arr) 
            hmp[e]++;
        
        for(auto it : hmp) 
            vs.push_back(it.second);

        sort(vs.begin(), vs.end(), greater<int>());
        
        int curr_size = N;
        for(auto v : vs) {
            count++;
            curr_size -= v;
            if(curr_size <= N/2)    
                break;
        }
        return count;
    }
};