class Solution {
public:
    enum Color {
        WHITE,
        BLUE,
        RED
    };
    bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
        vector<vector<int>> AdjList (N+1);
        for(int i = 0; i < dislikes.size(); i++) {
            int u = dislikes[i][0];
            int v = dislikes[i][1];
            AdjList[u].push_back(v);
            AdjList[v].push_back(u);
        }
        vector<int> visited(N+1, false);
        vector<Color> C(N+1, WHITE);
        queue<int> que;
        for(int i = 1; i<= N; i++) {
            que.push(i);
            C[i] = RED;
            while(!que.empty()) {
                int u = que.front();
                que.pop();
                if(visited[u])  continue;
                visited[u] = true;
                for(auto v : AdjList[u]) {
                    if(C[u] == C[v])    return false;
                    if(C[u] == RED) C[v] = BLUE;
                    else    C[v] = RED;
                    que.push(v);
                }
            }
        }
        
        return true;
    }
};