class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        if(image[sr][sc] == newColor)   
            return image;
        int Rows = image.size();
        int Cols = image[0].size();
        int R[] = {0, -1, 0, 1};
        int C[] = {-1, 0, 1, 0};
        int oldColor = image[sr][sc];
        image[sr][sc] = newColor;
        for(int i = 0; i < 4; i++) {
            int newR = R[i] + sr;
            int newC = C[i] + sc;
            if(newR >= 0 && newR < Rows && newC >= 0 && newC < Cols && image[newR][newC] == oldColor)
                floodFill(image, newR, newC, newColor);
        }
        return image;
    }
};