class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int element = 1;
        int index = 0;
        while( index < arr.size() && k ) {
            if(arr[index] == element)
                index++;
            else
                k--;
            element++;
        }
        element += k - 1;
        return element;
    }
};