class Solution {
public:
    bool dfs(int v,vector<bool> &vis,stack<int> &st,vector<vector<int>> &g,vector<bool> &rec)
    {
        vis[v] = true;
        rec[v] = true;
        bool y = false;
        for(int i=0;i<g[v].size();i++)
        {
            int u = g[v][i];
            if(rec[u] && vis[u])
                return true;
            if(!vis[u])
                y = y || dfs(u,vis,st,g,rec);
        }
        st.push(v);
        rec[v] = false;
        return y;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> g(numCourses);
        for(int i=0;i<prerequisites.size();i++)
            g[prerequisites[i][1]].push_back(prerequisites[i][0]);
        vector<bool> vis(numCourses,false), rec(numCourses,false);
        stack<int> st;
        vector<int> ans;
        for(int i=0;i<numCourses;i++)
        {
            if(!vis[i])
            {
                if(dfs(i,vis,st,g,rec))
                {
                    return ans;
                }
            }
        }
        while(!st.empty())
            ans.push_back(st.top()), st.pop();
        return ans;
    }
};
