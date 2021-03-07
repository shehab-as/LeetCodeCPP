class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        int A1_x1 = rec1[0], A1_y1 = rec1[1],
        A1_x2 = rec1[2], A1_y2 = rec1[3];
        
        int A2_x1 = rec2[0], A2_y1 = rec2[1],
        A2_x2 = rec2[2], A2_y2 = rec2[3];
        
        return (A1_x1 < A2_x2 && A2_x1 < A1_x2
                && A1_y1 < A2_y2 && A2_y1 < A1_y2);
    }
};

// bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
// 	int x1 = rec1[0], y1 = rec1[1], x2 = rec1[2], y2 = rec1[3];
// 	int x3 = rec2[0], y3 = rec2[1], x4 = rec2[2], y4 = rec2[3];
// 	return (x1 < x4 && x3 < x2 && y1 < y4 && y3 < y2);
// }