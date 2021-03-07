class Solution {
public:
    // O(N) Time Complexity.
    // O(N) Space Complexity.
    vector<int> findErrorNums(vector<int>& nums) {
        int N = nums.size();
        int sum = (N*(N+1))/2;
        int count = 0;
        // 1 -> N
        // [1,2,2,4]
        //  0 1 2 3 
        // 0 -> N-1
        int repeated = 0;
        for(int i = 0; i < N; i++) {
            if(nums[abs(nums[i]) - 1] > 0) {
                nums[abs(nums[i])-1] = -nums[abs(nums[i])-1];
                count += abs(nums[i]);
            } 
            else {
                repeated = abs(nums[i]);
            }
        }
        return {repeated, sum - count};
        
    }
    
    // // O(N) Time Complexity.
    // // O(N) Space Complexity.
    // vector<int> findErrorNums(vector<int>& nums) {
    //     int N = nums.size();
    //     int sum = (N*(N+1))/2;
    //     int count = 0;
    //     unordered_set<int> visited;
    //     int repeated = 1;
    //     for(int& e : nums) {
    //         if(visited.find(e) != visited.end()) {
    //             repeated = e;
    //         }
    //         else {
    //             count += e;
    //             visited.insert(e);
    //         }
    //     }
    //     return {repeated, sum - count};
    // }
};