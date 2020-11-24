class Solution {
public:
    int GetParent(vector<int>& parent, int index) {
        while(parent[index] != index)
            index = parent[index];
        return index;
    }
    
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int V = edges.size();
        vector<int> parent(V + 1);
        for(int i = 1; i <= V; i++)
            parent[i] = i;
        vector<int> res_edge;
        for(auto edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int uParent = GetParent(parent, u);
            int vParent = GetParent(parent, v);
            if(uParent == vParent)
                res_edge = edge;
            parent[uParent] = vParent;
        }
        return res_edge;
    }
};