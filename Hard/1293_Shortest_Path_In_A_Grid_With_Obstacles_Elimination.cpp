class Solution {
private:
    int BFS(vector<vector<int>>& grid,int k){
        vector<vector<int>> vis(grid.size(),vector<int>(grid[0].size(),-1));
        queue<vector<int>> q;
		
        q.push({0,0,0,k});
        while(!q.empty()){
            auto t=q.front();
            int x=t[0],y=t[1];
            int curr_k = t[3], curr_len = t[2];
            q.pop();
			
            if(x<0 || y<0 || x>=grid.size() || y>=grid[0].size()) {
                continue;
            }
			
            if(x==grid.size()-1 && y==grid[0].size()-1)
                return curr_len;

            if(grid[x][y]==1) {
                if(curr_k > 0) 
                    curr_k--;
                else
                    continue;
            }
			
            if(vis[x][y]!=-1 && vis[x][y]>=curr_k)
                continue;
            vis[x][y]=curr_k;
    
            q.push({x+1,y,curr_len+1,curr_k});
            q.push({x,y+1,curr_len+1,curr_k});
            q.push({x-1,y,curr_len+1,curr_k});
            q.push({x,y-1,curr_len+1,curr_k});
        }
        return -1;
    }
    
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        return BFS(grid, k);
    }
};