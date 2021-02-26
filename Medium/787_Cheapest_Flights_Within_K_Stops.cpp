class Solution {
public:
    void DFS(unordered_map<int, vector<pair<int,int>>>& g, int src, int dst, int K, int curr_price, int& final_price, vector<bool>& visited) {
        if(src == dst) {
            final_price = curr_price;
            return;
        }
        if(K == 0) 
            return;
        visited[src] = true;
        for(auto const&p : g[src]) {
            if(!visited[p.first]) {
                if(curr_price + p.second > final_price)   continue;   //prune
                DFS(g, p.first, dst, K-1, curr_price + p.second, final_price, visited);
            }
        }
        visited[src] = false;        
    }
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        vector<int> availablePrices;
        unordered_map<int, vector<pair<int,int>>> g;
        for(auto flight : flights) {
            g[flight[0]].push_back(make_pair(flight[1], flight[2]));
        }
        int ans = INT_MAX;
        vector<bool> visited(n, false);
        DFS(g, src, dst, K+1, 0, ans, visited);
        return ans == INT_MAX ? -1 : ans;
    }
};