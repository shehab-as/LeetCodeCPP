class Solution {
public:
    bool escapeGhosts(vector<vector<int>>& ghosts, vector<int>& target) {
        int escape_steps = abs(target[0]) + abs(target[1]);
        for(int i=0; i<ghosts.size(); i++) {
            vector<int> ghost = ghosts[i];
            int ghost_steps = abs(ghost[0]- target[0]) + abs(ghost[1] - target[1]);
            if(ghost_steps <= escape_steps)
                return false;
        }
        return true;
    }
};

