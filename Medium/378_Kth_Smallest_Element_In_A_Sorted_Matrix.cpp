class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<int, vector<int>, greater<int>> min_heap;
        for(int i = 0; i < matrix.size(); i++) {
            for(int j = 0; j < matrix[i].size(); j++) {
                min_heap.push(matrix[i][j]);
            }
        }
        while(k != 1) {
            min_heap.pop();
            k--;
        }
        return min_heap.top();
    }
};