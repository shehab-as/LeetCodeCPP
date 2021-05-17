class Solution {
private:
    vector<vector<int>> edges;
    vector<int> score;
    int DFS(int v) {
        if(score[v] > 0) {
            return score[v];
        }
        score[v] = 1;
        for(int vertex : edges[v]) {
            score[v] = max(score[v], DFS(vertex) + 1);
        }
        return score[v];
    }
public:
    int longestStrChain(vector<string>& words) {
        if(words.empty()) {
            return 0;
        }

        const int N = words.size();
        edges.clear();
        edges.resize(N);
        score.clear();
        score.resize(N);

        unordered_map<string, int> wordToidx;
        for(int i = 0; i < N; i++) {
            wordToidx[words[i]] = i;
        }
        
        for(int i = 0; i < N; i++) {
            string s = words[i];
            for(int j = 0; j < (int) s.length(); j++) {
                string s_copy = s;
                s_copy.erase(s_copy.begin() + j);
                auto it = wordToidx.find(s_copy);
                if(it == wordToidx.end()) {
                    continue;
                }
                edges[it->second].push_back(i);
            }
        }
        int ans = 0;
        for(int i = 0; i < N; i++) {
            ans = max(ans, DFS(i));
        }
        return ans;
    }
};