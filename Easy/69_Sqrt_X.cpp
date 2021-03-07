class Solution {
public:
    int mySqrt(int x) {
        int low = 1, high = x, mid, answer;
        if(x == 0)  return x;
        while(low <= high)
        {
            mid = low + ((high-low) / 2);
            if(mid <= x/mid)
            {
                answer = mid;
                low = mid + 1;
            }
            else
                high = mid - 1;
        }
        return answer;
    }
};