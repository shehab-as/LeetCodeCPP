class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        int index = count(arr.begin(), arr.end(), 0) + arr.size();
        for(int i = arr.size() - 1; i >= 0; i--) {
            if(--index < arr.size())
                arr[index] = arr[i];
            if(arr[i] == 0 && --index < arr.size())
                arr[index] = 0;
        }
    }
};
