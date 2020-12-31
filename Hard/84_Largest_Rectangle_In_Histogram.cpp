class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        // stack-based approach.
        // O(N) time complexity.
        int global_max = 0;
        int i = 0, N = heights.size();
        stack<int> indices;
        
        while( i <= N ) {
            while(i == N || (!indices.empty() && heights[indices.top()] > heights[i]))
            {
                int val = 0;
                if( i == N && indices.empty() ) 
                    i++;
                else {
                    val = heights[indices.top()];
                    indices.pop();
                }
                int left = indices.empty() ? -1 : indices.top();
                global_max = max( global_max, val * (i - left - 1) );
            }
            indices.push(i++);
        }
        
        return global_max;
    }
};


//     int largestRectangleArea(vector<int>& heights) {
//         // brute force approach.
//         // O(N^2) time complexity.
//         int global_max = 0;
//         int N = heights.size();
//         for(int i = 0; i < N; i++) {
//             int start = i - 1;
//             int end = i + 1;
//             int local_max = heights[i];
//             while( start >= 0 && heights[start] >= heights[i] ) {
//                 local_max += heights[i];
//                 start--;
//             } 
//             while( end < N && heights[end] >= heights[i] ) {
//                 local_max += heights[i];
//                 end++;
//             }
//             global_max = max(global_max, local_max);
//         }
//         return global_max;
//     }