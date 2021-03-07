class Solution {
public:
       int maxArea(vector<int>& height) {
           int area = -1, a;
           int l = 0, h = height.size()-1;
        
           while(l < h)
           {
               a = min(height[l], height[h]) * (h-l);
               if(area < a)
                   area = a;
               height[l] <= height[h] ? l++ : h--;
           }
           return area;
    }
    
    // int maxArea(vector<int>& height) {
    //     int area = INT_MIN, a;
    //     int i, j;
    //     for(i = 1; i<height.size(); i++)
    //     {
    //         j = i - 1;
    //         while(j>=0)
    //         {
    //             a = min(height[i], height[j]) * (i-j);
    //             if(area < a)
    //                 area = a;
    //             j--;
    //         }
    //     }
    //     return area;
    // }
};