class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string, multiset<string>> AdjList;
        vector<string> itinerary;
        for(auto ticket : tickets) {
            AdjList[ticket[0]].insert(ticket[1]);
        }
        stack<string> dfs;
        dfs.push("JFK");
        while(!dfs.empty()) {
            string topAirport = dfs.top();
            if(AdjList[topAirport].empty()) {
                itinerary.push_back(topAirport);
                dfs.pop();
            }
            else {
                string dest = *AdjList[topAirport].begin();
                dfs.push(dest);
                AdjList[topAirport].erase(AdjList[topAirport].begin());
            }
        }
        reverse(itinerary.begin(), itinerary.end());
        return itinerary;
    }
};
