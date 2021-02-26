class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if(matrix.empty())  return {};
        int M = matrix.size();
        int N = matrix[0].size();
        vector<int> result;
        int topIndx = 0, bottomIndx = M - 1;
        int leftIndx = 0, rightIndx = N - 1;
        while( topIndx <= bottomIndx && leftIndx <= rightIndx ) {
            for(int j = leftIndx; j <= rightIndx; j++) 
                result.push_back(matrix[topIndx][j]);
            topIndx++;
            
            // if(topIndx > bottomIndx)    break;
            for(int i = topIndx; i <= bottomIndx; i++)
                result.push_back(matrix[i][rightIndx]);
            rightIndx--;

            // if(leftIndx > rightIndx)    break;
            for(int j = rightIndx; j >= leftIndx && topIndx <= bottomIndx; j--)
                result.push_back(matrix[bottomIndx][j]);
            bottomIndx--;
            
            for(int i = bottomIndx; i >= topIndx && leftIndx <= rightIndx; i--)
                result.push_back(matrix[i][leftIndx]);
            leftIndx++;

        }
        return result;
    }
};