class Solution {
public:
    void VisitAll(int u, vector<vector<int>>& rooms, vector<bool>& visited) {
        if(visited[u])  return;
        visited[u] = true;
        for(auto it = rooms[u].begin(); it != rooms[u].end(); it++) {
            if(!visited[*it])
                VisitAll(*it, rooms, visited);
        }
        return;
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<bool> visited(rooms.size(), false);
        VisitAll(0, rooms, visited);
        for(bool v : visited) 
            if(!v)  return false;
        return true;
    }
};