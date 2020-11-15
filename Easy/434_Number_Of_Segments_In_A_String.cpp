class Solution {
public:
    int countSegments(string s) {
        int segments = 0;
        s += ' ';
        char prev = ' ';
        for(char& c : s) {
            if(c == ' ' && prev != ' ')    segments++;
            prev = c;
        }
        return segments;
    }
};