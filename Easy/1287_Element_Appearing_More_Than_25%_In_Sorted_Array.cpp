class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int majority = ceil(arr.size() / 4);
        int curr_occ = 1;
        int result = arr[0];
        for(int i = 0; i < arr.size() - 1; i++) {
            if(arr[i] == arr[i+1])
                curr_occ++;
            else
                curr_occ = 1;
            result = (curr_occ >= majority) ? arr[i] : result;
        }
        return result;
    }
};