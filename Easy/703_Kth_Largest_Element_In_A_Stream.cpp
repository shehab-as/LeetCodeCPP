class KthLargest {
private:
    priority_queue<int, vector<int>, greater<int>> min_pq;
    int _k;
public:
    KthLargest(int k, vector<int>& nums) : _k(k) {
        int i = 0;
        while(i < nums.size()) {
            min_pq.push(nums[i]);
            if(min_pq.size() > _k) {
                min_pq.pop();
            }
            i++;
        }
    }
    
    int add(int val) {
        min_pq.push(val);
        if(min_pq.size() > _k) {
            min_pq.pop();
        }
        return min_pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */