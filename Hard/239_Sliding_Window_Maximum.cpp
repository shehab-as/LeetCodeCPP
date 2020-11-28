class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if(nums.empty())    return {};
        deque<int> window;
        vector<int> result;
        for(int i = 0; i < nums.size(); i++) {
            if(!window.empty() && window.front() == i - k)
                window.pop_front();
            while(!window.empty() && nums[window.back()] < nums[i])
                window.pop_back();
            window.push_back(i);
            if(i >= k-1)
                result.push_back(nums[window.front()]);
        }
        return result;
    }
};