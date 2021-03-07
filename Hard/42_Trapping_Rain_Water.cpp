class Solution {
public:
    int trap(vector<int>& height) {
        int trapped = 0;
        int left = 0, right = height.size() - 1;
        int lmax = 0, rmax = 0;
        
        while(left < right)
        {
            if(height[left] < height[right])
            {
                if(height[left] > lmax)
                    lmax = height[left];
                else
                {
                    trapped += lmax - height[left];
                    left++;
                }
            }
            
            else
            {
                if(height[right] > rmax)
                    rmax = height[right];
                else
                {
                    trapped += rmax - height[right];
                    right--;
                }
            }
        }
        return trapped;
    }
};