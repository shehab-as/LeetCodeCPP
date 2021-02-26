class Solution {
public:
    vector<int> prisonAfterNDays(vector<int>& cells, int N) {
        if( N < 0 ) return {};
        vector<int> curr(cells.size(), 0);
        vector<int> source(cells.size(), 0);
        for(int cycle = 0; N-- > 0; cycle++) {
            for(int i = 1; i < cells.size() - 1; i++)
                curr[i] = cells[i-1] == cells[i+1];
            if(cycle == 0)  
                source = curr;
            else if(source == curr)
                N %= cycle;
            cells = curr;
        }
        return cells;
    }
};
