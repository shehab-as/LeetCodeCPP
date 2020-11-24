class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>> pq;
        for(int& e : nums)  pq.push(e);
        while(k>1) {
            pq.pop();
            k--;
        }
        return pq.top();
    }
};