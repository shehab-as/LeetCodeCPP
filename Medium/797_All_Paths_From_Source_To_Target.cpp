class Solution {
public:
    
    void DFS(const vector<vector<int>>& graph, vector<vector<int>>& all_paths, vector<int> one_path, int u) {
        if(u == graph.size() - 1) {
            all_paths.push_back(one_path);
            return;
        }
        for(int i = 0; i < graph[u].size(); i++) {
            one_path.push_back(graph[u][i]);
            DFS(graph, all_paths, one_path, graph[u][i]);
            one_path.pop_back();
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> all_paths;
        vector<int> one_path;
        one_path.push_back(0);
        DFS(graph, all_paths, one_path, 0);
        return all_paths;
    }
};