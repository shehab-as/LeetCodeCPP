class Solution {
public:
    bool judgeCircle(string moves) {
        pair<int, int> Origin (0,0);
        for(int i=0; i<moves.length(); i++)
        {
            if(moves[i] == 'U')
                Origin.second++;
            else if (moves[i] == 'D')
                Origin.second--;
            else if (moves[i] == 'R')
                Origin.first++;
            else //moves[i] == 'L'
                Origin.first--;
        }
        return (Origin == make_pair(0,0));
    }
};