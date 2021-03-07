class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0)
            return 0;
        priority_queue<int> q;
        for(int i=0; i<nums.size(); i++)
            q.push(nums[i]);
        
        int n = 1;
        int max_n = 1;
        int lc = q.top();
        q.pop();
        while(!q.empty())
        {
            if(lc - q.top() == 1)
                n++;
            else if(lc - q.top() != 0)
            {
                max_n = max(max_n, n);
                n = 1;
            }
            lc = q.top();
            q.pop();
        }
        max_n = max(max_n, n);
        return max_n;
    }
};