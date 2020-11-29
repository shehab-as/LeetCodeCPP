class Solution {
public:
    bool SearchForZero(vector<int>& arr, int index, vector<bool> visited) {
        if(index >= arr.size() || index < 0 || visited[index]) return false;
        if(arr[index] == 0) return true;
        visited[index] = true;
        if( SearchForZero(arr, index + arr[index], visited) )
            return true;
        if( SearchForZero(arr, index - arr[index], visited) ) 
            return true;
        visited[index] = false;
        return false;
    }
    bool canReach(vector<int>& arr, int start) {
        vector<bool> visited(arr.size(), false);
        return SearchForZero(arr, start, visited);
    }
};