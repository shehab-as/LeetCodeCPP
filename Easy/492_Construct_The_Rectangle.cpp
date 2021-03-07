class Solution {
public:
    vector<int> constructRectangle(int area) {
        int N = floor(sqrt(area));
        while(area % N != 0)    N--;
        int L = area/N, W = N;
        return {L, W};
    }
};