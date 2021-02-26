class Solution {
public:
    int CountSoldiers(const vector<int>& row) {
        int low = 0, high = row.size() - 1;
        while(low <= high) {
            int m = low + (high-low)/2;
            if(row[m] == 1)
                low = m + 1;
            else if(row[m] == 0)
                high = m - 1;
        }
        return low;
    }
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<int> result;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;  //min_q
        int rows = mat.size();
        for(int i = 0; i < rows; i++) {
            int count = CountSoldiers(mat[i]);
            pq.push(make_pair(count, i));
        }
        while(!pq.empty() && k) {
            result.push_back(pq.top().second);
            pq.pop();
            k--;
        }
        return result;
    }
};